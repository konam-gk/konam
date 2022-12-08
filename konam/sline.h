// Structural Line

#ifndef SLINE_H
#define SLINE_H


#include "spoint.h"
#include "sline_container.h"
#include "cross_section.h"

#include <array>
#include <string>
#include "constraints.h"
#include <memory>
#include <string>

using namespace std::string_literals;


class SLine
{
protected:

	//SLine() : m_newId{ structural_line_number_counter() }, m_element_type{ "NONE" },
	//	m_number_of_elements{ 0 }, m_group{ 0 }, m_support{ "FREE" },
	//	m_cross_sections{ 0, 0 }, m_points{ nullptr, nullptr }
	//{
	//	//this->m_newId = this->structural_line_number_counter();
	//	this->insert(this->m_newId, *this);

	//	//this->m_element_type = "NONE";
	//	//this->m_number_of_elements = 0;
	//	//this->m_group = 0;
	//	//this->m_support = "FREE";

	//	//for (std::size_t i{}; i < 2; ++i) {
	//	//	this->m_cross_sections[i] = 0;
	//	//	this->m_points[i] == nullptr;
	//	//}
	//}


public:

	enum class Type { NONE, BEAM, TRUSS, CABLE };

	SLine(unsigned int newId, SPoint& spStart, SPoint& spEnd)	// add optional variables
		: m_newId{ newId }, m_points{ std::make_shared<SPoint>(spStart), std::make_shared<SPoint>(spEnd) },
		m_element_type{ "NONE" }, m_cross_sections{ 0, 0 }, m_group{ 0 }, m_number_of_elements{ 0 },
		m_support{ "FREE" }
	{
		this->insert(this->m_newId, *this);
	}
	//static std::unique_ptr<SLine> pointer()
	//{
	//	struct EnableMaker : public SLine { using SLine::SLine; };
	//	return std::make_unique<EnableMaker>();
	//}


	//void add_newId(const unsigned int num)
	//{
	//	this->m_newId = num;
	//}


	void add_start_point(const SPoint& sp)
	{
		this->check_coordinates();
		this->m_points[0] = std::make_shared<SPoint>(sp);
	}


	void add_end_point(const SPoint& sp)
	{
		this->check_coordinates();
		this->m_points[1] = std::make_shared<SPoint>(sp);
	}


	void add_element_type(const SLine::Type type)
	{
		if (type != SLine::Type::NONE) this->check_if_cross_section_is_assigned();

		std::string temp{};

		switch (type) {
		case Type::NONE:
			temp = "NONE";
			break;
		case Type::BEAM:
			temp = "BEAM";
			break;
		case Type::TRUSS:
			temp = "TRUSS";
			break;
		case Type::CABLE:
			temp = "CABLE";
		}

		this->m_element_type = temp;
	}


	void add_section_at_start(const unsigned int num)
	{
		Cross_Section::find_cross_section_number(num);
		this->m_cross_sections[0] = num;
		this->m_cross_sections[1] = num;
	}


	void add_section_at_end(const unsigned int num)
	{
		Cross_Section::find_cross_section_number(num);
		this->check_if_cross_section_is_assigned();
		this->m_cross_sections[1] = num;
	}


	void add_number_of_elements(const unsigned int num)
	{
		this->m_number_of_elements = num;
	}


	void add_support(std::string fix)
	{
		Constraints::check_support_type(fix);
		this->m_support = fix;
	}


	inline auto number() const
	{
		return this->m_newId;
	}


	inline auto cross_section_at_start() const
	{
		return this->m_cross_sections[0];
	}


	inline auto cross_section_at_end() const
	{
		return this->m_cross_sections[1];
	}


	inline auto material_number()
	{
		this->check_if_cross_section_is_assigned();
		return Cross_Section::material_number(this->cross_section_at_start());
	}


	inline auto element_type() const
	{
		return this->m_element_type;
	}


	void set_number(unsigned int newId)
	{
		this->check_if_structural_line_number_exists(newId);
		if (m_newId > 999999)
			throw std::out_of_range("Invalid Structural-Line number. Error in file " __FILE__);
		this->m_newId = newId;
	}


	//inline auto start_point() const
	//{
	//	return this->m_points[0]->number();
	//}


	//inline auto end_point() const
	//{
	//	return this->m_points[1]->number();
	//}


	inline double length()
	{
		auto coord = this->points_coordinates();
		double value{};

		double temp{};	// temporary variable
		for (unsigned int i = 1; i < m_points.size(); ++i) {
			temp = 0.0;
			for (unsigned int j = 0; j < GSDefinition::get_number_of_dimensions(); ++j)
				temp += std::pow(coord(i, j) - coord(i - 1, j), 2);
			value += std::sqrt(temp);
		}
		return value;
	}


	//inline auto point_ptr(const int num) const
	//{
	//	return m_points[num];
	//}


private:

	unsigned int m_newId;
	std::string m_support;
	std::array<std::shared_ptr<SPoint>, 2> m_points;
	std::array<unsigned int, 2> m_cross_sections;
	unsigned int m_group;
	std::string m_element_type;
	unsigned int m_number_of_elements;


	// map container of structural lines
	static inline std::map<unsigned int, SLine> ms_sline_map;


	void insert(const unsigned int num, SLine& section)
	{
		auto pr = ms_sline_map.emplace(num, section);
		if (!pr.second)
			throw std::invalid_argument("Structural line number "s + std::to_string(num) +
				" already exists. Error in file: " __FILE__);
	}


	bool check_if_structural_line_number_exists(unsigned int key)
	{
		if (auto it = ms_sline_map.find(key); it == ms_sline_map.end())
			return false;

		return true;
	}


	void check_if_cross_section_is_assigned()
	{
		if (this->cross_section_at_start() == 0)
			throw std::invalid_argument("No cross-section is assigned to the structural line."
				" Error if file: " __FILE__);
	}


	konam_mat points_coordinates()
	{
		// number of points
		const auto npts = this->m_points.size();
		konam_mat coord(npts, GSDefinition::get_number_of_dimensions());

		for (unsigned int i = 0; i < npts; ++i)
			for (unsigned int j = 0; j < GSDefinition::get_number_of_dimensions(); ++j)
				coord(i, j) = this->m_points[i]->coordinate(j + 1);

		return coord;
	}


	//int structural_line_number_counter()
	//{
	//	int sline_number = ++SLine::count;
	//	bool check = SLine::check_if_structural_line_number_exists(sline_number);
	//	while (check) {
	//		sline_number = ++SLine::count;
	//		check = SLine::check_if_structural_line_number_exists(sline_number);
	//	}
	//	return sline_number;
	//}


	static inline unsigned int count{};
	static constexpr double k_limit{ 1.0e-6 };


	void check_coordinates()
	{
		if (GSDefinition::get_number_of_dimensions() != 3 &&
			(std::abs(m_points[0]->z_coord()) > k_limit) || (std::abs(m_points[1]->z_coord()) > k_limit))
			throw std::out_of_range("Te coordinates of structural lines "s + std::to_string(this->m_newId) +
				" are not lying within the plane of the defined system. Error in file " __FILE__);
	}


};


#endif // !SLINE_H
