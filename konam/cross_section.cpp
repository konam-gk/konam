#include "cross_section.h"

#include <cmath>
#include <algorithm>


std::unique_ptr<Circle> Cross_Section::Circle()
{
	struct EnableMaker : public Circle { using Circle::Circle; };
	return std::make_unique<EnableMaker>();
}


std::unique_ptr<Rectangle> Cross_Section::Rectangle()
{
	struct EnableMaker : public Rectangle { using Rectangle::Rectangle; };
	return std::make_unique<EnableMaker>();
}


//std::unique_ptr<Polygon> Cross_Section::Polygon()
//{
//	struct EnableMaker : public Polygon { using Polygon::Polygon; };
//	return std::make_unique<EnableMaker>();
//}


bool Cross_Section::check_if_cross_section_number_exists(int key)
{
	if (auto it = ms_csection_map.find(key); it == ms_csection_map.end())
		return false;

	return true;
}


void Cross_Section::find_cross_section_number(int key)
{
	if (!check_if_cross_section_number_exists(key))
		throw std::invalid_argument("Cross section number "s + std::to_string(key) +
			" does not exists. Error in file: " __FILE__);
}


int Cross_Section::cross_section_number_counter()
{
	int section_number = ++Cross_Section::count;
	bool check = Cross_Section::check_if_cross_section_number_exists(section_number);
	while (check) {
		section_number = ++Cross_Section::count;
		check = Cross_Section::check_if_cross_section_number_exists(section_number);
	}
	return section_number;
}


void Cross_Section::set_cross_section_number(int current_value, int new_value)
{
	auto check = check_if_cross_section_number_exists(new_value);

	if ((check && current_value == new_value) || !check) {
		auto new_key = ms_csection_map.extract(current_value);
		new_key.key() = new_value;
		ms_csection_map.insert(std::move(new_key));
	}
	else {
		throw std::invalid_argument("Cross section number "s + std::to_string(new_value) +
			" already exists. Error in file: " __FILE__);
	}

	check_value(Parameter::Section_number, new_value);
}


std::pair<double, double> Cross_Section::get_min_max(Parameter prop)
{
	double max{}, min{};

	switch (prop) {
	case Parameter::Section_number:
		max = 999.0;
		min = 1.0;
		break;
	case Parameter::Width:
	case Parameter::Height:
	case Parameter::Radius:
		max = 100.0;
		min = 0.0001;
		break;
	}

	return std::minmax(max, min);
}


// Explicit template instantiation
template void Cross_Section::check_value(Parameter, int);
template void Cross_Section::check_value(Parameter, double);
template void Cross_Section::check_value(Parameter, float);
template void Cross_Section::check_value(Parameter, unsigned int);

template<typename T>
void Cross_Section::check_value(Parameter prop, T value)
{
	auto [min, max] = get_min_max(prop);

	switch (prop) {
	case Parameter::Section_number:
		if (typeid(value) != typeid(int))
			throw std::invalid_argument("Cross section number must be an integer number. "
				"Error in file: " __FILE__);
		if (value < min || value > max)
			throw std::out_of_range("Invalid cross section number. Error in file: " __FILE__);
		break;
	case Parameter::Width:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of width. Error in file: " __FILE__);
		break;
	case Parameter::Height:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of height. Error in file: " __FILE__);
		break;
	case Parameter::Radius:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of radius. Error in file: " __FILE__);
		break;
	}
}


var_sec_t Cross_Section::cross_section_type(const unsigned int key)
{
	find_cross_section_number(key);
	auto& temp = ms_csection_map.find(key)->second;
	var_sec_t w = std::visit([](auto&& arg) -> var_sec_t { return arg; }, temp);
	return w;
}


//void Cross_Section::set_all_parameters_to_default(const unsigned int key)
//{
//	auto w = cross_section_type(key);
//	std::visit([](auto&& arg) {
//		arg.set_width(k_Width);
//		arg.set_height(k_Height);
//		arg.set_radius(k_Radius);
//		}, w);
//}


int Cross_Section::material_number(const unsigned int key)
{
	auto w = cross_section_type(key);
	int value;
	std::visit([&value](auto&& arg) { value = arg.get_material_number(); }, w);
	return value;
}


double Cross_Section::area(const unsigned int key)
{
	auto w = cross_section_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_area(); }, w);
	return value;
}


//double Cross_Section::shear_area(const unsigned int key)
//{
//	auto w = cross_section_type(key);
//	double value;
//	std::visit([&value](auto&& arg) { value = arg.get_shear_area(); }, w);
//	return value;
//}


double Cross_Section::perimeter(const unsigned int key)
{
	auto w = cross_section_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_perimeter(); }, w);
	return value;
}


double Cross_Section::moment_of_inertia_y(const unsigned int key)
{
	auto w = cross_section_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_moment_of_inertia_y(); }, w);
	return value;
}


double Cross_Section::moment_of_inertia_z(const unsigned int key)
{
	auto w = cross_section_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_moment_of_inertia_z(); }, w);
	return value;
}


//double Cross_Section::torsion_constant(const unsigned int key)
//{
//	auto w = cross_section_type(key);
//	double value;
//	std::visit([&value](auto&& arg) { value = arg.get_torsion_constant(); }, w);
//	return value;
//}


//void Cross_Section::save_in_container(const int key)
//{
//	const auto w = cross_section_type(key);
//
//	double value;
//	std::visit([](auto&& arg) {
//		std::get<0>(ms_csection_map.find(1)->second).m_cross_section_number = arg.get_section_number();
//		std::get<w>(ms_csection_map.find(key)->second).m_area = arg.get_area();
//		std::get<w>(ms_csection_map.find(key)->second).m_perimeter = arg.get_perimeter();
//		std::get<w>(ms_csection_map.find(key)->second).m_moment_of_inertia_y = arg.get_moment_of_inertia_y();
//		std::get<w>(ms_csection_map.find(key)->second).m_moment_of_inertia_z = arg.get_moment_of_inertia_z();
//		std::get<w>(ms_csection_map.find(key)->second).m_moment_of_inertia_yz = arg.get_moment_of_inertia_yz();
//		std::get<w>(ms_csection_map.find(key)->second).m_centroid = arg.get_centroid();
//		std::get<w>(ms_csection_map.find(key)->second).m_title = arg.get_title();
//		}, w);
//}