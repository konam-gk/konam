#include "material.h"
#include <cmath>


Concrete::Concrete(Concrete::Class type)
{
	m_material_number = ++Material::count;

	//Material::insert(m_material_number, *this);

	//this->set_parameters(type);
}


int Concrete::get_material_number() const
{
	return m_material_number;
}


double Concrete::get_elastic_modulus() const
{
	return m_elastic_modulus;
}


double Concrete::get_poisson_ratio() const
{
	return m_poisson_ratio;
}


double Concrete::get_shear_modulus() const
{
	return m_shear_modulus;
}


double Concrete::get_bulk_modulus() const
{
	return m_bulk_modulus;
}


double Concrete::get_specific_weight() const
{
	return m_specific_weight;
}


double Concrete::get_elongation_coefficient() const
{
	return m_elongation_coefficient;
}


double Concrete::get_safety_factor() const
{
	return m_safety_factor;
}


std::string Concrete::get_type() const
{
	return m_type;
}


double Concrete::get_acc() const
{
	return m_acc;
}


double Concrete::get_compressive_strength() const
{
	return m_compressive_strength;
}


double Concrete::get_tensile_strength() const
{
	return m_tensile_strength;
}


double Concrete::get_strain_at_peak_stress() const
{
	return m_strain_at_peak_stress;
}


double Concrete::get_ultimate_strain() const
{
	return m_ultimate_strain;
}


double Concrete::compressive_stress_at_deformation(const double value)
{
	if (value < 0.0)
		throw std::invalid_argument("Deformation must be greater than zero. Error in file: " __FILE__);

	auto EPC = this->get_strain_at_peak_stress();
	auto EPCU = this->get_ultimate_strain();
	auto FC = this->get_compressive_strength();
	auto gam = this->get_safety_factor();
	auto FCD = FC / gam;
	auto acc = this->get_acc();
	auto FCK = FC / acc;

	auto n = [&FCK]() {return FCK >= 50.0 ? (1.4 + 23.4 * std::pow(((90.0 - FCK) / 100.0), 4)) : 2.0; };

	return EPC <= EPCU ? FCD * (1.0 - std::pow((1.0 - (value / EPC)), n())) : FCD;
}


// set General properties

//void Concrete::set_elastic_modulus(double value, std::optional<std::string> opt)
//{
//	auto check = opt.value_or("ON");
//	Material::check_optional_input_argument_for_elastic_constant(check);
//
//	Material::check_value(Material::Parameter::Elastic_modulus, value);
//	m_elastic_modulus = value;
//	this->save_in_container();
//	//std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = value;
//
//	if (check == "ON")
//		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
//			Material::Elastic_Constant::Poisson_ratio, m_material_number);
//}
//
//
//void Concrete::set_poisson_ratio(double value, std::optional<std::string> opt)
//{
//	auto check = opt.value_or("ON");
//	Material::check_optional_input_argument_for_elastic_constant(check);
//
//	Material::check_value(Material::Parameter::Poisson_ratio, value);
//	m_poisson_ratio = value;
//	this->save_in_container();
//
//	if (check == "ON")
//		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
//			Material::Elastic_Constant::Poisson_ratio, m_material_number);
//}
//
//
//void Concrete::set_shear_modulus(double value, std::optional<std::string> opt)
//{
//	auto check = opt.value_or("ON");
//	Material::check_optional_input_argument_for_elastic_constant(check);
//
//	Material::check_value(Material::Parameter::Shear_modulus, value);
//	m_shear_modulus = value;
//	this->save_in_container();
//
//	if (check == "ON")
//		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
//			Material::Elastic_Constant::Shear_modulus, m_material_number);
//}
//
//
//void Concrete::set_bulk_modulus(double value, std::optional<std::string> opt)
//{
//	auto check = opt.value_or("ON");
//	Material::check_optional_input_argument_for_elastic_constant(check);
//
//	Material::check_value(Material::Parameter::Bulk_modulus, value);
//	m_bulk_modulus = value;
//	this->save_in_container();
//
//	if (check == "ON")
//		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Poisson_ratio,
//			Material::Elastic_Constant::Bulk_modulus, m_material_number);
//}
//
//
//void Concrete::set_specific_weight(double value)
//{
//	Material::check_value(Material::Parameter::Specific_weight, value);
//	m_specific_weight = value;
//	this->save_in_container();
//}
//
//
//void Concrete::set_elongation_coefficient(double value)
//{
//	Material::check_value(Material::Parameter::Elongation_coefficient, value);
//	m_elongation_coefficient = value;
//	this->save_in_container();
//}
//
//
//void Concrete::set_safety_factor(double value)
//{
//	Material::check_value(Material::Parameter::Safety_factor, value);
//	m_safety_factor = value;
//	this->save_in_container();
//}
//
//
//void Concrete::set_type(Concrete::Class type)
//{
//	this->set_parameters(type);
//}
//
//
//void Concrete::set_parameters(Concrete::Class type)
//{
//	// characteristic compressive cylinder strength of concrete at 28 days
//	double FCK{};
//	// mean tensile strength
//	double FCTM{};
//	// coefficient for compressive strength
//	const double acc = this->get_acc();
//	// mean compressive strength
//	double FCM{};
//	// effective compressive strength
//	double FC{};
//
//
//	auto tensile_strength = [&FCK, &FCM]() {
//		return FCK <= 50.0 ? 0.3 * std::pow(FCK, (2.0 / 3.0)) :
//		2.12 * std::log(1.0 + (FCM / 10.0)); 
//	};
//	auto strain_c2 = [&FCK]() { return FCK >= 50.0 ? 2.0 + 0.085 * std::pow((FCK - 50.0), 0.53) : 2.0; };
//	auto strain_cu2 = [&FCK]() { return FCK >= 50.0 ? 2.6 + 35.0 * std::pow((90.0 - FCK) / 100.0, 4) : 3.5; };
//	auto mean_stress = [&FCK]() {return FCK + 8.0; };
//
//
//	switch (type) {
//	case Concrete::Class::C12:
//		FCK = 12.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C16:
//		FCK = 16.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C20:
//		FCK = 20.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C25:
//		FCK = 25.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C30:
//		FCK = 30.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C35:
//		FCK = 35.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C40:
//		FCK = 40.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C45:
//		FCK = 45.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C50:
//		FCK = 50.0;
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C55:
//		FCK = 55.0;
//		FCM = mean_stress();
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C60:
//		FCK = 60.0;
//		FCM = mean_stress();
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C70:
//		FCK = 70.0;
//		FCM = mean_stress();
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C80:
//		FCK = 80.0;
//		FCM = mean_stress();
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	case Concrete::Class::C90:
//		FCK = 90.0;
//		FCM = mean_stress();
//		FCTM = tensile_strength();
//		FC = acc * FCK;
//		// strains [云
//		this->m_strain_at_peak_stress = strain_c2();
//		this->m_ultimate_strain = strain_cu2();
//		break;
//	}
//
//
//	// classification
//	this->m_type = "C"s + std::to_string(static_cast<int>(FCK));
//	//std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_type = m_type;	// error
//
//	// elastic modulus
//	double EC = 22000.0 * std::pow((FCM / 10.0), 0.3);
//
//	this->set_elastic_modulus(EC);					// [MPa]
//	this->set_compressive_strength(FC);				// [MPa]
//	this->set_tensile_strength(FCTM);				// [MPa]
//	this->set_poisson_ratio(0.200);					// [-]
//	this->set_specific_weight(25.0);				// [kN/m3]
//	this->set_elongation_coefficient(1.000e-5);		// [1/K]
//	this->set_safety_factor(1.500);					// [-]
//
//	Material::parameters_conversion_for_two_independent_constants(
//		Material::Elastic_Constant::Elastic_modulus, Material::Elastic_Constant::Poisson_ratio,
//		m_material_number);
//}
//
//
//// set Strength (General)
//
//void Concrete::set_acc(double value)
//{
//	Concrete::check_strength_value(Concrete::Strength::ACC_coefficient, value);
//	m_acc = value;
//	this->save_in_container();
//}
//
//
//void Concrete::set_compressive_strength(double value)
//{
//	Concrete::check_strength_value(Concrete::Strength::Compressive_strength, value);
//	m_compressive_strength = value;
//	this->save_in_container();
//}
//
//
//void Concrete::set_tensile_strength(double value)
//{
//	Concrete::check_strength_value(Concrete::Strength::Tensile_strength, value);
//	m_tensile_strength = value;
//	this->save_in_container();
//}
//
//
//void Concrete::save_in_container()
//{
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_material_number = m_material_number;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = m_elastic_modulus;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio = m_poisson_ratio;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus = m_shear_modulus;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus = m_bulk_modulus;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight = m_specific_weight;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient = m_elongation_coefficient;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor = m_safety_factor;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_type = m_type;
//
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_strain_at_peak_stress = m_strain_at_peak_stress;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_ultimate_strain = m_ultimate_strain;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_acc = m_acc;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_compressive_strength = m_compressive_strength;
//	std::get<Concrete>(Material::ms_material_map.find(m_material_number)->second).m_tensile_strength = m_tensile_strength;
//}
//
//
//std::pair<double, double> Concrete::get_min_max(Concrete::Strength prop)
//{
//	double max{}, min{};
//
//	switch (prop) {
//	case Strength::ACC_coefficient:
//		max = 1.0;
//		min = 0.8;
//		break;
//	case Strength::Compressive_strength:
//		max = 500.0;
//		min = 10.0;
//		break;
//	case Strength::Tensile_strength:
//		max = 10.0;
//		min = 0.0;
//		break;
//	}
//
//	return std::minmax(max, min);
//}
//
//
//void Concrete::check_strength_value(Concrete::Strength prop, double value)
//{
//	auto [min, max] = get_min_max(prop);
//
//	switch (prop) {
//	case Strength::ACC_coefficient:
//		if (value < min || value > max)
//			throw std::out_of_range("Invalid value of coefficient for compressive strength. Error in file: " __FILE__);
//		break;
//	case Strength::Compressive_strength:
//		if (value < min || value > max)
//			throw std::out_of_range("Invalid value of effective strength. Error in file: " __FILE__);
//		break;
//	case Strength::Tensile_strength:
//		if (value < min || value > max)
//			throw std::out_of_range("Invalid value of tensile strength. Error in file: " __FILE__);
//		break;
//	}
//}