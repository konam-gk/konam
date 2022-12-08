#include "von_mises.h"
#include "material.h"


Von_Mises::Von_Mises()
{
	m_material_number = Material::material_number_counter();

	Material::check_value(Material::Parameter::Material_number, m_material_number);
	Material::insert(m_material_number, *this);

	this->set_all_parameters_to_default();
}


int Von_Mises::get_material_number() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_material_number;
}


double Von_Mises::get_elastic_modulus() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus;
}


double Von_Mises::get_poisson_ratio() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio;
}


double Von_Mises::get_shear_modulus() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus;
}


double Von_Mises::get_bulk_modulus() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus;
}


double Von_Mises::get_lame_constant() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant;
}


double Von_Mises::get_specific_weight() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight;
}


double Von_Mises::get_elongation_coefficient() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient;
}


double Von_Mises::get_safety_factor() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor;
}


std::string Von_Mises::get_title() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_title;
}


double Von_Mises::get_yield_stress() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_yield_stress;
}


double Von_Mises::get_hardening_modulus() const
{
	return std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_hardening_modulus;
}


void Von_Mises::set_material_number(int value)
{
	Material::set_material_number(m_material_number, value);
	m_material_number = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_material_number = value;
}


void Von_Mises::set_elastic_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Elastic_modulus, value);
	m_elastic_modulus = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Von_Mises::set_poisson_ratio(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Poisson_ratio, value);
	m_poisson_ratio = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
			Material::Elastic_Constant::Poisson_ratio, m_material_number);
}


void Von_Mises::set_shear_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Shear_modulus, value);
	m_shear_modulus = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Shear_modulus, m_material_number);
}


void Von_Mises::set_bulk_modulus(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Bulk_modulus, value);
	m_bulk_modulus = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Bulk_modulus, m_material_number);
}


void Von_Mises::set_lame_constant(double value, std::optional<std::string> opt)
{
	Material::check_value(Material::Parameter::Lame_constant, value);
	m_lame_constant = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_lame_constant = value;

	auto check = opt.value_or("ON");
	Material::check_optional_input_argument_for_elastic_constant(check);

	if (check == "ON")
		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
			Material::Elastic_Constant::Lame_constant, m_material_number);
}


void Von_Mises::set_specific_weight(double value)
{
	Material::check_value(Material::Parameter::Specific_weight, value);
	m_specific_weight = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight = value;
}


void Von_Mises::set_elongation_coefficient(double value)
{
	Material::check_value(Material::Parameter::Elongation_coefficient, value);
	m_elongation_coefficient = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient = value;
}


void Von_Mises::set_safety_factor(double value)
{
	Material::check_value(Material::Parameter::Safety_factor, value);
	m_safety_factor = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor = value;
}


void Von_Mises::set_title(std::string title)
{
	if (title.size() > 20)
		title.resize(20);

	m_title = title;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_title = title;
}


void Von_Mises::set_yield_stress(double value)
{
	Material::check_value(Material::Parameter::Yield_strength, value);
	m_yield_stress = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_yield_stress = value;
}


void Von_Mises::set_hardening_modulus(double value)
{
	Material::check_value(Material::Parameter::Yield_strength, value);
	m_hardening_modulus = value;
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).m_hardening_modulus = value;
}


void Von_Mises::set_all_parameters_to_default()
{
	Material::set_all_parameters_to_default(m_material_number);

	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).set_yield_stress(0.0);
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).set_hardening_modulus(0.0);
	std::get<Von_Mises>(Material::ms_material_map.find(m_material_number)->second).set_title("von Mises");
}


double Von_Mises::von_Mises_stress(const std::array<double, 6>& stress)
{
	// temporary variables
	const auto sigx = stress[0];
	const auto sigy = stress[1];
	const auto sigz = stress[2];
	const auto tauxy = stress[3];
	const auto tauyz = stress[4];
	const auto tauzx = stress[5];
	const auto sigxsigy = sigx - sigy;
	const auto sigysigz = sigy - sigz;
	const auto sigzsigx = sigz - sigx;

	// invariant
	const auto t = std::sqrt(sigxsigy * sigxsigy + sigysigz * sigysigz + sigzsigx * sigzsigx
		+ 6.0 * (tauxy * tauxy + tauyz * tauyz + tauzx * tauzx)) / std::sqrt(3.0);

	return std::sqrt(1.5) * t;
}


double Von_Mises::yield_criterion(const std::array<double, 6>& stress)
{
	// von-Mises stress
	const auto deviator_stress = von_Mises_stress(stress);

	// shear stresses
	const auto tauxy = stress[3];
	const auto tauyz = stress[4];
	const auto tauzx = stress[5];

	//const auto H = get_hardening_modulus();
	//const auto Y0 = get_yield_stress();
	//auto Yep = Y0 + H;

	// Yield criterion
	auto Fvm = deviator_stress - 2.0 * (tauxy + tauyz + tauzx);

	return Fvm;
}