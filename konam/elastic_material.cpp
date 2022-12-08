#include "elastic_material.h"
#include "material.h"


Elastic_Material::Elastic_Material()
{
	m_material_number = Material::material_number_counter();

	Material::check_value(Material::Parameter::Material_number, m_material_number);
	Material::insert(m_material_number, *this);

	this->set_all_parameters_to_default();
}


int Elastic_Material::get_material_number() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_material_number;
}


double Elastic_Material::get_elastic_modulus() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus;
}


double Elastic_Material::get_poisson_ratio() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio;
}


double Elastic_Material::get_shear_modulus() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus;
}


double Elastic_Material::get_bulk_modulus() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus;
}


double Elastic_Material::get_lame_constant() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant;
}


double Elastic_Material::get_specific_weight() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight;
}


double Elastic_Material::get_elongation_coefficient() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient;
}


double Elastic_Material::get_safety_factor() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor;
}


std::string Elastic_Material::get_title() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_title;
}


double Elastic_Material::get_yield_strength() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_yield_strength;
}


double Elastic_Material::get_ultimate_strength() const
{
	return std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_ultimate_strength;
}


void Elastic_Material::set_material_number(unsigned int value)
{
	Material::set_material_number(m_material_number, value);
	m_material_number = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_material_number = value;
}


void Elastic_Material::set_elastic_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Elastic_modulus, value);
	m_elastic_modulus = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = value;
	
	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Elastic_Material::set_poisson_ratio(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Poisson_ratio, value);
	m_poisson_ratio = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Elastic_Material::set_shear_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Shear_modulus, value);
	m_shear_modulus = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Shear_modulus, m_material_number);
}


void Elastic_Material::set_bulk_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Bulk_modulus, value);
	m_bulk_modulus = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Bulk_modulus, m_material_number);
}


void Elastic_Material::set_lame_constant(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Lame_constant, value);
	m_lame_constant = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);
	
	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Lame_constant, m_material_number);
}


void Elastic_Material::set_specific_weight(double value)
{
	Material::check_value(Material::Parameter::Specific_weight, value);
	m_specific_weight = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight = value;
}


void Elastic_Material::set_elongation_coefficient(double value)
{
	Material::check_value(Material::Parameter::Elongation_coefficient, value);
	m_elongation_coefficient = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient = value;
}


void Elastic_Material::set_safety_factor(double value)
{
	Material::check_value(Material::Parameter::Safety_factor, value);
	m_safety_factor = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor = value;
}


void Elastic_Material::set_title(std::string title)
{
	if (title.size() > 20)
		title.resize(20);

	m_title = title;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_title = title;
}


void Elastic_Material::set_yield_strength(double value)
{
	Material::check_value(Material::Parameter::Yield_strength, value);
	m_yield_strength = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_yield_strength = value;
}


void Elastic_Material::set_ultimate_strength(double value)
{
	Material::check_value(Material::Parameter::Ultimate_strength, value);
	m_ultimate_strength = value;
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).m_ultimate_strength = value;
}


void Elastic_Material::set_all_parameters_to_default()
{
	Material::set_all_parameters_to_default(m_material_number);

	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).set_yield_strength(0.0);
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).set_ultimate_strength(0.0);
	std::get<Elastic_Material>(Material::ms_material_map.find(m_material_number)->second).set_title("Elastic Material");
}