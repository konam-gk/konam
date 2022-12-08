// Structural Point

#ifndef SPOINT_H
#define SPOINT_H


#include <optional>
#include <string_view>

#include "vertex.h"
#include "global_system_definition.h"
#include <array>
#include <cmath>	// std::abs


class SPoint
{
protected:

	//SPoint() : m_vertex{ std::make_shared<Vertex>(structural_point_number_counter(), 0.0, 0.0, 0.0) }
	//{
	//}


public:

	// x, y, z
	SPoint(unsigned int number, double xCoord, double yCoord, double zCoord)
		: m_vertex{ std::make_shared<Vertex>(number, xCoord, yCoord, zCoord) }
	{
		if (GSDefinition::get_number_of_dimensions() != 3)
			throw std::out_of_range("Invalid number of coordinates. Error in file " __FILE__);
	}

	// x, y
	SPoint(unsigned int number, double xCoord, double yCoord)
		: m_vertex{ std::make_shared<Vertex>(number, xCoord, yCoord, 0.0) }
	{
		if (GSDefinition::get_number_of_dimensions() != 2)
			throw std::out_of_range("Invalid number of coordinates. Error in file " __FILE__);
	}


	double coordinate(const int coord) const
	{
		return this->m_vertex->coordinate(coord);
	}


	//static inline konam_vec point_coordinates(int node)
	//{
	//	return this->m_vertex->node_coordinates(node);
	//}


	unsigned int number() const
	{
		return this->m_vertex->number();
	}


	double x_coord() const
	{
		return this->m_vertex->x_coord();
	}


	double y_coord() const
	{
		return this->m_vertex->y_coord();
	}


	double z_coord() const
	{
		return this->m_vertex->z_coord();
	}


	//std::array<double, 3> add_coordinates(double x, double y, double z)
	//{
	//	this->m_vertex->set_coord(x, y, z);
	//}


	//unsigned int add_number(unsigned int num)
	//{
	//	this->m_vertex->set_Id(num);
	//}


private:

	std::shared_ptr<Vertex> m_vertex;


	// map container of structural points
	static inline std::map<unsigned int, SPoint> ms_spoint_map;


	void insert(const unsigned int num, SPoint& section)
	{
		auto pr = ms_spoint_map.emplace(num, section);
		if (!pr.second)
			throw std::invalid_argument("Structural point number "s + std::to_string(num) +
				" already exists. Error in file: " __FILE__);
	}


	bool check_if_structural_point_number_exists(unsigned int key)
	{
		if (auto it = ms_spoint_map.find(key); it == ms_spoint_map.end())
			return false;

		return true;
	}


	int structural_point_number_counter()
	{
		int spoint_number = ++SPoint::count;
		bool check = SPoint::check_if_structural_point_number_exists(spoint_number);
		while (check) {
			spoint_number = ++SPoint::count;
			check = SPoint::check_if_structural_point_number_exists(spoint_number);
		}
		return spoint_number;
	}

	static inline unsigned int count{};

};

#endif // !SPOINT_H
