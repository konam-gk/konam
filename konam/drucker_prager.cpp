#include "drucker_prager.h"
#include "material.h"


Drucker_Prager::Drucker_Prager()
{
	m_material_number = Material::material_number_counter();

	Material::check_value(Material::Parameter::Material_number, m_material_number);
	Material::insert(m_material_number, *this);

	this->set_all_parameters_to_default();
}


int Drucker_Prager::get_material_number() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_material_number;
}


double Drucker_Prager::get_elastic_modulus() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus;
}


double Drucker_Prager::get_poisson_ratio() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio;
}


double Drucker_Prager::get_shear_modulus() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus;
}


double Drucker_Prager::get_bulk_modulus() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus;
}


double Drucker_Prager::get_lame_constant() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant;
}


double Drucker_Prager::get_specific_weight() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight;
}


double Drucker_Prager::get_elongation_coefficient() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient;
}


double Drucker_Prager::get_safety_factor() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor;
}


std::string Drucker_Prager::get_title() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_title;
}


double Drucker_Prager::get_friction_angle() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_friction_angle;
}


double Drucker_Prager::get_cohesion() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_cohesion;
}


double Drucker_Prager::get_tensile_strength() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_tensile_strength;
}


double Drucker_Prager::get_dilation_angle() const
{
	return std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_dilation_angle;
}


void Drucker_Prager::set_material_number(int value)
{
	Material::set_material_number(m_material_number, value);
	m_material_number = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_material_number = value;
}


void Drucker_Prager::set_elastic_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Elastic_modulus, value);
	m_elastic_modulus = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Drucker_Prager::set_poisson_ratio(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Poisson_ratio, value);
	m_poisson_ratio = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio = value;
	
	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Drucker_Prager::set_shear_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Shear_modulus, value);
	m_shear_modulus = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Shear_modulus, m_material_number);
}


void Drucker_Prager::set_bulk_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Bulk_modulus, value);
	m_bulk_modulus = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Bulk_modulus, m_material_number);
}


void Drucker_Prager::set_lame_constant(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Lame_constant, value);
	m_lame_constant = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Lame_constant, m_material_number);
}


void Drucker_Prager::set_specific_weight(double value)
{
	Material::check_value(Material::Parameter::Specific_weight, value);
	m_specific_weight = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight = value;
}


void Drucker_Prager::set_elongation_coefficient(double value)
{
	Material::check_value(Material::Parameter::Elongation_coefficient, value);
	m_elongation_coefficient = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient = value;
}


void Drucker_Prager::set_safety_factor(double value)
{
	Material::check_value(Material::Parameter::Safety_factor, value);
	m_safety_factor = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor = value;
}


void Drucker_Prager::set_title(std::string title)
{
	if (title.size() > 20)
		title.resize(20);

	m_title = title;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_title = title;
}


void Drucker_Prager::set_friction_angle(double value)
{
	Material::check_value(Material::Parameter::Friction_angle, value);
	m_friction_angle = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_friction_angle = value;
}


void Drucker_Prager::set_cohesion(double value)
{
	Material::check_value(Material::Parameter::Cohesion, value);
	m_cohesion = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_cohesion = value;
}


void Drucker_Prager::set_tensile_strength(double value)
{
	Material::check_value(Material::Parameter::Tensile_strength, value);
	m_tensile_strength = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_tensile_strength = value;
}


void Drucker_Prager::set_dilation_angle(double value)
{
	Material::check_value(Material::Parameter::Dilation_angle, value);
	m_dilation_angle = value;
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).m_dilation_angle = value;
}


void Drucker_Prager::set_all_parameters_to_default()
{
	Material::set_all_parameters_to_default(m_material_number);

	// Mohr-Coulomb parameters
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).set_friction_angle(0.0);
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).set_cohesion(0.0);
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).set_tensile_strength(0.0);
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).set_dilation_angle(0.0);
	std::get<Drucker_Prager>(Material::ms_material_map.find(m_material_number)->second).set_title("Mohr-Coulomb");
}


//double Drucker_Prager::yield_criterion(const std::array<double, 6>& stress)
//{
//	// first stress invariant
//	const double I1 = Tensor_Utilities::invariant_I1(stress);
//
//	// second deviatoric stress invariant
//	const double J2 = Tensor_Utilities::invariant_J2(stress);
//
//	// Lode angle
//	double theta = Tensor_Utilities::lode_angle(stress);
//
//	// friction angle
//	const auto fi = get_friction_angle();
//
//	// cohesion
//	const auto c = get_cohesion();
//
//	// Yield criterion
//	double Fdp = I1 * std::sin(fi) / 3.0 + std::sqrt(J2) * (std::cos(theta) - (std::sin(theta) * std::sin(fi)) / std::sqrt(3.0)) - c * std::cos(fi);
//
//	return Fdp;
//}