#include "circle.h"
#include "cross_section.h"
#include "constants.h"
#include "material.h"


Circle::Circle()
{
	m_cross_section_number = Cross_Section::cross_section_number_counter();

	Cross_Section::check_value(Cross_Section::Parameter::Section_number, m_cross_section_number);
	Cross_Section::insert(m_cross_section_number, *this);
	
	this->set_all_parameters_to_default();
}


void Circle::calculator_of_properties(const double value)
{
	m_radius = value;
	m_area = constants::k_PI * m_radius * m_radius;
	//m_perimeter = 2.0 * constants::k_PI * m_radius;
	m_moment_of_inertia_y = 0.25 * constants::k_PI * std::pow(m_radius, 4);
	m_moment_of_inertia_z = m_moment_of_inertia_y;
	m_torsion_moment_of_inertia = 0.03125 * constants::k_PI * std::pow(m_radius, 4);

	this->save_in_container();
}


int Circle::get_cross_section_number() const
{
	return m_cross_section_number;
}


int Circle::get_material_number() const
{
	return m_material_number;
}


double Circle::get_radius() const
{
	return m_radius;
}


double Circle::get_diameter() const
{
	return 2.0 * m_radius;
}


double Circle::get_perimeter() const
{
	return m_perimeter;
}


double Circle::get_area() const
{
	return m_area;
}


double Circle::get_moment_of_inertia_y() const
{
	return m_moment_of_inertia_y;
}


double Circle::get_moment_of_inertia_z() const
{
	return m_moment_of_inertia_z;
}


double Circle::get_moment_of_inertia_yz() const
{
	return m_moment_of_inertia_yz;
}


double Circle::get_torsion_moment_of_inertia() const
{
	return m_torsion_moment_of_inertia;
}
//
//
//double Circle::get_shear_area() const
//{
//	return std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_shear_area;
//}


std::string Circle::get_title() const
{
	return m_title;
}


void Circle::set_cross_section_number(unsigned int value)
{
	Cross_Section::set_cross_section_number(m_cross_section_number, value);
	m_cross_section_number = value;
	this->save_in_container();
}


void Circle::set_material_number(int value)
{
	Material::find_material_number(value);
	m_material_number = value;
	this->save_in_container();
}


void Circle::set_radius(double value)
{
	Cross_Section::check_value(Cross_Section::Parameter::Radius, value);
	calculator_of_properties(value);
}


void Circle::set_diameter(double value)
{
	set_radius(0.5 * value);
}


void Circle::set_title(std::string title)
{
	if (title.size() > 20)
		title.resize(20);

	m_title = title;
	this->save_in_container();
}


void Circle::set_all_parameters_to_default()
{
	this->set_material_number(Cross_Section::k_num);
	this->set_radius(0.30);
	this->set_title("Circle");
}


void Circle::save_in_container()
{
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_cross_section_number = m_cross_section_number;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_material_number = m_material_number;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_area = m_area;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_perimeter = m_perimeter;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_radius = m_radius;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_y = m_moment_of_inertia_y;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_z = m_moment_of_inertia_z;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_moment_of_inertia_yz = m_moment_of_inertia_yz;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_torsion_moment_of_inertia = m_torsion_moment_of_inertia;
	std::get<Circle>(Cross_Section::ms_csection_map.find(m_cross_section_number)->second).m_title = m_title;
}