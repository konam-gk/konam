#include "mohr_coulomb.h"
#include "material.h"


Mohr_Coulomb::Mohr_Coulomb()
{
	m_material_number = Material::material_number_counter();
	
	Material::check_value(Material::Parameter::Material_number, m_material_number);
	Material::insert(m_material_number, *this);

	this->set_all_parameters_to_default();
}


int Mohr_Coulomb::get_material_number() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_material_number;
}


double Mohr_Coulomb::get_elastic_modulus() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus;
}


double Mohr_Coulomb::get_poisson_ratio() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio;
}


double Mohr_Coulomb::get_shear_modulus() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus;
}


double Mohr_Coulomb::get_bulk_modulus() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus;
}


double Mohr_Coulomb::get_lame_constant() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant;
}


double Mohr_Coulomb::get_specific_weight() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight;
}


double Mohr_Coulomb::get_elongation_coefficient() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient;
}


double Mohr_Coulomb::get_safety_factor() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor;
}


std::string Mohr_Coulomb::get_title() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_title;
}


double Mohr_Coulomb::get_friction_angle() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_friction_angle;
}


double Mohr_Coulomb::get_cohesion() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_cohesion;
}


double Mohr_Coulomb::get_tensile_strength() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_tensile_strength;
}


double Mohr_Coulomb::get_dilation_angle() const
{
	return std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_dilation_angle;
}


void Mohr_Coulomb::set_material_number(int value)
{
	Material::set_material_number(m_material_number, value);
	m_material_number = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_material_number = value;
}


void Mohr_Coulomb::set_elastic_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Elastic_modulus, value);
	m_elastic_modulus = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if(check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Mohr_Coulomb::set_poisson_ratio(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Poisson_ratio, value);
	m_poisson_ratio = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Mohr_Coulomb::set_shear_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Shear_modulus, value);
	m_shear_modulus = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Shear_modulus, m_material_number);
}


void Mohr_Coulomb::set_bulk_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Bulk_modulus, value);
	m_bulk_modulus = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Bulk_modulus, m_material_number);
}


void Mohr_Coulomb::set_lame_constant(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Lame_constant, value);
	m_lame_constant = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Lame_constant, m_material_number);
}


void Mohr_Coulomb::set_specific_weight(double value)
{
	Material::check_value(Material::Parameter::Specific_weight, value);
	m_specific_weight = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight = value;
}


void Mohr_Coulomb::set_elongation_coefficient(double value)
{
	Material::check_value(Material::Parameter::Elongation_coefficient, value);
	m_elongation_coefficient = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient = value;
}


void Mohr_Coulomb::set_safety_factor(double value)
{
	Material::check_value(Material::Parameter::Safety_factor, value);
	m_safety_factor = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor = value;
}


void Mohr_Coulomb::set_title(std::string title)
{
	if (title.size() > 20)
		title.resize(20);

	m_title = title;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_title = title;
}


void Mohr_Coulomb::set_friction_angle(double value)
{
	Material::check_value(Material::Parameter::Friction_angle, value);
	m_friction_angle = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_friction_angle = value;
}


void Mohr_Coulomb::set_cohesion(double value)
{
	Material::check_value(Material::Parameter::Cohesion, value);
	m_cohesion = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_cohesion = value;
}


void Mohr_Coulomb::set_tensile_strength(double value)
{
	Material::check_value(Material::Parameter::Tensile_strength, value);
	m_tensile_strength = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_tensile_strength = value;
}


void Mohr_Coulomb::set_dilation_angle(double value)
{
	Material::check_value(Material::Parameter::Dilation_angle, value);
	m_dilation_angle = value;
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).m_dilation_angle = value;
}


void Mohr_Coulomb::set_all_parameters_to_default()
{
	Material::set_all_parameters_to_default(m_material_number);

	// Mohr-Coulomb parameters
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).set_friction_angle(0.0);
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).set_cohesion(0.0);
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).set_tensile_strength(0.0);
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).set_dilation_angle(0.0);
	std::get<Mohr_Coulomb>(Material::ms_material_map.find(m_material_number)->second).set_title("Mohr-Coulomb");
}


double Mohr_Coulomb::yield_criterion(const std::array<double, 6>& stress)
{
	// first stress invariant
	const double I1 = Tensor_Utilities::invariant_I1(stress);

	// second deviatoric stress invariant
	const double J2 = Tensor_Utilities::invariant_J2(stress);

	// Lode angle
	double theta = Tensor_Utilities::lode_angle(stress);

	// friction angle
	const auto fi = get_friction_angle();

	// cohesion
	const auto c = get_cohesion();

	// Yield criterion
	double Fmc = I1 * std::sin(fi) / 3.0 + std::sqrt(J2) * (std::cos(theta) - (std::sin(theta) * std::sin(fi)) / std::sqrt(3.0)) - c * std::cos(fi);

	return Fmc;
}