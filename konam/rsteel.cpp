#include "material.h"


RSteel::RSteel(RSteel::Class type)
{
	m_material_number = ++Material::count;

	//Material::insert(m_material_number, *this);

	//this->set_parameters(type);
}


int RSteel::get_material_number() const
{
	return m_material_number;
}


double RSteel::get_elastic_modulus() const
{
	return m_elastic_modulus;
}


double RSteel::get_poisson_ratio() const
{
	return m_poisson_ratio;
}


double RSteel::get_shear_modulus() const
{
	return m_shear_modulus;
}


double RSteel::get_bulk_modulus() const
{
	return m_bulk_modulus;
}


double RSteel::get_specific_weight() const
{
	return m_specific_weight;
}


double RSteel::get_elongation_coefficient() const
{
	return m_elongation_coefficient;
}


double RSteel::get_safety_factor() const
{
	return m_safety_factor;
}


std::string RSteel::get_type() const
{
	return m_type;
}


// set General properties

//void RSteel::set_elastic_modulus(double value, std::optional<std::string> opt)
//{
//	auto check = opt.value_or("ON");
//	Material::check_optional_input_argument_for_elastic_constant(check);
//
//	Material::check_value(Material::Parameter::Elastic_modulus, value);
//	m_elastic_modulus = value;
//	this->save_in_container();
//	//std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = value;
//
//	if (check == "ON")
//		Material::parameters_conversion_for_two_independent_constants(Material::Elastic_Constant::Elastic_modulus,
//			Material::Elastic_Constant::Poisson_ratio, m_material_number);
//}
//
//
//void RSteel::set_poisson_ratio(double value, std::optional<std::string> opt)
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
//void RSteel::set_shear_modulus(double value, std::optional<std::string> opt)
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
//void RSteel::set_bulk_modulus(double value, std::optional<std::string> opt)
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
//void RSteel::set_specific_weight(double value)
//{
//	Material::check_value(Material::Parameter::Specific_weight, value);
//	m_specific_weight = value;
//	this->save_in_container();
//}
//
//
//void RSteel::set_elongation_coefficient(double value)
//{
//	Material::check_value(Material::Parameter::Elongation_coefficient, value);
//	m_elongation_coefficient = value;
//	this->save_in_container();
//}
//
//
//void RSteel::set_safety_factor(double value)
//{
//	Material::check_value(Material::Parameter::Safety_factor, value);
//	m_safety_factor = value;
//	this->save_in_container();
//}
//
//
//void RSteel::set_type(RSteel::Class type)
//{
//	this->set_parameters(type);
//}
//
//
//void RSteel::set_parameters(RSteel::Class type)
//{
//	// yield strength
//	double FY{};
//	// ultimate strength
//	double FU{};
//	// strain at yield strength
//	double EPY{};
//	// ultimate strain
//	double EPU{};
//	// Class A, B, C
//	char Class2{};
//
//	switch (type) {
//	case RSteel::Class::B220A:
//		FY = 220.00;
//		FU = 340.00;
//		EPY = 1.100;
//		EPU = EPY;
//		Class2 = 'A';
//		break;
//	case RSteel::Class::B220B:
//		FY = 220.00;
//		FU = 340.00;
//		EPY = 1.100;
//		EPU = EPY;
//		Class2 = 'B';
//		break;
//	case RSteel::Class::B220C:
//		FY = 220.00;
//		FU = 340.00;
//		EPY = 1.100;
//		EPU = EPY;
//		Class2 = 'C';
//		break;
//	case RSteel::Class::B450A:
//		FY = 450.00;
//		FU = 472.50;
//		EPY = 2.250;
//		EPU = 25.000;
//		Class2 = 'A';
//		break;
//	case RSteel::Class::B450B:
//		FY = 450.00;
//		FU = 486.00;
//		EPY = 2.250;
//		EPU = 50.000;
//		Class2 = 'B';
//		break;
//	case RSteel::Class::B450C:
//		FY = 450.00;
//		FU = 517.50;
//		EPY = 2.250;
//		EPU = 75.000;
//		Class2 = 'C';
//		break;
//	case RSteel::Class::B500A:
//		FY = 500.00;
//		FU = 525.00;
//		EPY = 2.500;
//		EPU = 25.000;
//		Class2 = 'A';
//		break;
//	case RSteel::Class::B500B:
//		FY = 500.00;
//		FU = 540.00;
//		EPY = 2.500;
//		EPU = 50.000;
//		Class2 = 'B';
//		break;
//	case RSteel::Class::B500C:
//		FY = 500.00;
//		FU = 575.00;
//		EPY = 2.500;
//		EPU = 75.000;
//		Class2 = 'C';
//		break;
//	case RSteel::Class::B550B:
//		FY = 550.00;
//		FU = 594.00;
//		EPY = 2.750;
//		EPU = 50.000;
//		Class2 = 'B';
//		break;
//	case RSteel::Class::B600B:
//		FY = 600.00;
//		FU = 648.00;
//		EPY = 3.000;
//		EPU = 50.000;
//		Class2 = 'B';
//		break;
//	case RSteel::Class::B670B:
//		FY = 670.00;
//		FU = 800.00;
//		EPY = 3.350;
//		EPU = 50.000;
//		Class2 = 'B';
//		break;
//	}
//
//
//	// classification
//	m_type = "B"s + std::to_string(static_cast<int>(FY)) + Class2;
//	//std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_type = m_type;	// error
//
//	this->set_elastic_modulus(200000.0);			// [MPa]
//	this->set_yield_strength(FY);					// [MPa]
//	this->set_ultimate_strength(FU);				// [MPa]
//	this->set_strain_at_yield_strength(EPY);		// [‰]
//	this->set_ultimate_strain(EPU);					// [‰]
//	this->set_poisson_ratio(0.300);					// [-]
//	this->set_specific_weight(78.5);				// [kN/m3]
//	this->set_elongation_coefficient(1.200e-5);		// [1/K]
//	this->set_safety_factor(1.150);					// [-]
//
//	Material::parameters_conversion_for_two_independent_constants(
//		Material::Elastic_Constant::Elastic_modulus, Material::Elastic_Constant::Poisson_ratio,
//		m_material_number);
//}
//
//
//// set Strength (General)
//
//void RSteel::set_yield_strength(double value)
//{
//	if (value > m_ultimate_strength)
//		throw std::invalid_argument("Yield strength must be equal or lower than "
//			"Ultimate strength. Error in file: " __FILE__);
//
//	RSteel::check_strength_value(RSteel::Strength::Yield_strength, value);
//	m_yield_strength = value;
//	this->save_in_container();
//}
//
//
//void RSteel::set_ultimate_strength(double value)
//{
//	if (value < m_yield_strength)
//		throw std::invalid_argument("Ultimate strength must be equal or greater than "
//			"Yield strength. Error in file: " __FILE__);
//
//	RSteel::check_strength_value(RSteel::Strength::Ultimate_strength, value);
//	m_ultimate_strength = value;
//	this->save_in_container();
//}
//
//
//void RSteel::set_strain_at_yield_strength(double value)
//{
//	if (value > m_ultimate_strain)
//		throw std::invalid_argument("Yield strain must be equal or lower than "
//			"Ultimate strain. Error in file: " __FILE__);
//
//	RSteel::check_strength_value(RSteel::Strength::Strain_at_yield_strength, value);
//	m_strain_at_yield_strength = value;
//	this->save_in_container();
//}
//
//
//void RSteel::set_ultimate_strain(double value)
//{
//	if (value < m_strain_at_yield_strength)
//		throw std::invalid_argument("Ultimate strain must be equal or greater than "
//			"Yield strain. Error in file: " __FILE__);
//
//	RSteel::check_strength_value(RSteel::Strength::Ultimate_strain, value);
//	m_ultimate_strain = value;
//	this->save_in_container();
//}
//
//
//void RSteel::save_in_container()
//{
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_material_number = m_material_number;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_elastic_modulus = m_elastic_modulus;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_poisson_ratio = m_poisson_ratio;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_shear_modulus = m_shear_modulus;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_bulk_modulus = m_bulk_modulus;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_specific_weight = m_specific_weight;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_elongation_coefficient = m_elongation_coefficient;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_safety_factor = m_safety_factor;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_type = m_type;
//
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_yield_strength = m_yield_strength;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_ultimate_strength = m_ultimate_strength;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_strain_at_yield_strength = m_strain_at_yield_strength;
//	std::get<RSteel>(Material::ms_material_map.find(m_material_number)->second).m_ultimate_strain = m_ultimate_strain;
//}
//
//
//std::pair<double, double> RSteel::get_min_max(RSteel::Strength prop)
//{
//	double max{}, min{};
//
//	switch (prop) {
//	case Strength::Yield_strength:
//		max = 1000.0;
//		min = 0.0;
//		break;
//	case Strength::Ultimate_strength:
//		max = 1000.0;
//		min = 10.0;
//		break;
//	case Strength::Strain_at_yield_strength:
//		max = 100.0;
//		min = 0.0;
//		break;
//	case Strength::Ultimate_strain:
//		max = 1000.0;
//		min = 100.0;
//		break;
//	}
//
//	return std::minmax(max, min);
//}
//
//
//void RSteel::check_strength_value(RSteel::Strength prop, double value)
//{
//	auto [min, max] = get_min_max(prop);
//
//	switch (prop) {
//	case Strength::Yield_strength:
//		if (value < min || value > max)
//			throw std::out_of_range("Invalid value of yield strength. Error in file: " __FILE__);
//		break;
//	case Strength::Ultimate_strength:
//		if (value < min || value > max)
//			throw std::out_of_range("Invalid value of ultimate strength. Error in file: " __FILE__);
//		break;
//	case Strength::Strain_at_yield_strength:
//		if (value < min || value > max)
//			throw std::out_of_range("Invalid value of strain at yield strength. Error in file: " __FILE__);
//		break;
//	case Strength::Ultimate_strain:
//		if (value < min || value > max)
//			throw std::out_of_range("Invalid value of ultimate strain. Error in file: " __FILE__);
//		break;
//	}
//}