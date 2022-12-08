#include "rectangle.h"
#include "cross_section.h"
#include "constants.h"
#include "material.h"


Rectangle::Rectangle()
{
	m_cross_section_number = Cross_Section::cross_section_number_counter();

	Cross_Section::check_value(Cross_Section::Parameter::Section_number, m_cross_section_number);
	Cross_Section::insert(m_cross_section_number, *this);

	this->set_all_parameters_to_default();
}


void Rectangle::calculator_of_properties(const double value, const std::string& prop)
{
	if (prop == "WIDTH") {
		m_width = value;
		std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_width = m_width;
		m_area = value * m_height;
		m_moment_of_inertia_y = value * std::pow(m_height, 3) / 12.0;
		m_moment_of_inertia_z = m_height * std::pow(value, 3) / 12.0;

		//auto const h_w = m_height / value;
		//m_torsion_constant = m_width * std::pow(m_height, 3) * ((1.0 / 3.0) - 0.21 * h_w * (1.0 - std::pow(h_w, 4) / 12.0));
	}
	else if (prop == "HEIGHT") {
		m_height = value;
		std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_height = m_height;
		m_area = m_width * value;
		m_moment_of_inertia_y = m_width * std::pow(value, 3) / 12.0;
		m_moment_of_inertia_z = value * std::pow(m_width, 3) / 12.0;

		//auto const h_w = value / m_width;
		//m_torsion_constant = m_width * std::pow(value, 3) * ((1.0 / 3.0) - 0.21 * h_w * (1.0 - std::pow(h_w, 4) / 12.0));
	}
	else
		throw std::invalid_argument("Error in file: " __FILE__);


	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_area = m_area;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_y = m_moment_of_inertia_y;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_z = m_moment_of_inertia_z;
	//std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_torsion_constant = m_torsion_constant;

	//m_shear_area = 0.0;
	//std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_shear_area = m_shear_area;
}


int Rectangle::get_cross_section_number() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_cross_section_number;
}


int Rectangle::get_material_number() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_material_number;
}



double Rectangle::get_width() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_width;
}


double Rectangle::get_height() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_height;
}


double Rectangle::get_perimeter() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_perimeter;
}


double Rectangle::get_area() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_area;
}


double Rectangle::get_moment_of_inertia_y() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_y;
}


double Rectangle::get_moment_of_inertia_z() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_z;
}


//double Rectangle::get_torsion_constant() const
//{
//	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_torsion_constant;
//}
//
//
//double Rectangle::get_shear_area() const
//{
//	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_shear_area;
//}


std::string Rectangle::get_title() const
{
	return std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_title;
}


void Rectangle::set_cross_section_number(unsigned int value)
{
	Cross_Section::set_cross_section_number(m_cross_section_number, value);
	m_cross_section_number = value;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_cross_section_number = value;
}


void Rectangle::set_material_number(int value)
{
	Material::find_material_number(value);
	m_material_number = value;
	this->save_in_container();
}


void Rectangle::set_width(double value)
{
	Cross_Section::check_value(Cross_Section::Parameter::Width, value);
	calculator_of_properties(value, "WIDTH");
}


void Rectangle::set_height(double value)
{
	Cross_Section::check_value(Cross_Section::Parameter::Height, value);
	calculator_of_properties(value, "HEIGHT");
}


void Rectangle::set_title(std::string title)
{
	if (title.size() > 20)
		title.resize(20);

	m_title = title;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_title = m_title;
}


void Rectangle::set_all_parameters_to_default()
{
	this->set_material_number(Cross_Section::k_num);
	this->m_width = 0.30;
	this->m_height = 0.30;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_width = m_width;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_height = m_height;
	this->calculator_of_properties(m_width, "WIDTH");
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).set_title("Rectangle");
}


void Rectangle::save_in_container()
{
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_cross_section_number = m_cross_section_number;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_material_number = m_material_number;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_area = m_area;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_perimeter = m_perimeter;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_y = m_moment_of_inertia_y;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_z = m_moment_of_inertia_z;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_yz = m_moment_of_inertia_yz;
	//std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_centroid = m_centroid;
	std::get<Rectangle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_title = m_title;
}