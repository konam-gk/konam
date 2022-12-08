#ifndef CROSS_SECTION_H
#define CROSS_SECTION_H


#include <map>
#include <stdexcept>
#include <variant>
#include <memory>
#include <algorithm>	// std::transform

#include "circle.h"
#include "rectangle.h"
//#include "polygon.h"


using namespace std::string_literals;

//using var_t = std::variant<Circle, Rectangle, Polygon>;
using var_sec_t = std::variant<Circle, Rectangle>;


class Cross_Section
{
private:

	Cross_Section() = delete;

	friend class Circle;
	friend class Rectangle;
	friend class Polygon;


	// map container of cross-sections
	static inline std::map<unsigned int, var_sec_t> ms_csection_map;

	template<typename T>
	static inline void insert(const int num, T& section)
	{
		auto pr = ms_csection_map.emplace(num, section);
		if (!pr.second)
			throw std::invalid_argument("Cross section number "s + std::to_string(num) + " already exists. Error in file: " __FILE__);
	}


	// Default Parameters
	static const int k_num = 1;	                    // default cross section and material number
	static constexpr double k_Width = 0.30;         // default width
	static constexpr double k_Height = 0.30;        // default height
	static constexpr double k_Radius = 0.30;		// default radius


	enum class Parameter { Section_number, Width, Height, Radius };

	static bool check_if_cross_section_number_exists(int key);

	//static void find_cross_section_number(int key);

	static int cross_section_number_counter();

	static void set_cross_section_number(int current_value, int new_value);

	static inline unsigned int count{};

	static std::pair<double, double> get_min_max(Parameter prop);

	template<typename T> static void check_value(Parameter prop, T value);

	static var_sec_t cross_section_type(const unsigned int key);


public:

	static std::unique_ptr<Circle> Circle();
	static std::unique_ptr<Rectangle> Rectangle();
	//static std::unique_ptr<Polygon> Polygon();

	static int material_number(const unsigned int key);
	static double area(const unsigned int key);
	//static double shear_area(const unsigned int key);
	static double perimeter(const unsigned int key);
	static double moment_of_inertia_y(const unsigned int key);
	static double moment_of_inertia_z(const unsigned int key);
	//static double torsion_constant(const unsigned int key);
	static void find_cross_section_number(int key);

};



#endif // !CROSS_SECTION_H