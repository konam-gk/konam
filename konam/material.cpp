#include "material.h"

#include <cmath>
#include <algorithm>

#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric::ublas;


std::unique_ptr<Elastic_Material> Material::Elastic_Material()
{
	struct EnableMaker : public Elastic_Material { using Elastic_Material::Elastic_Material; };
	return std::make_unique<EnableMaker>();
}


std::unique_ptr<Mohr_Coulomb> Material::Mohr_Coulomb()
{
	struct EnableMaker : public Mohr_Coulomb { using Mohr_Coulomb::Mohr_Coulomb; };
	return std::make_unique<EnableMaker>();
}


bool Material::check_if_material_number_exists(int key)
{
	if (ms_material_map.contains(key))
		return true;

	return false;

	//if (auto it = ms_material_map.find(key); it == ms_material_map.end())
	//	return false;

	//return true;
}


void Material::find_material_number(int key)
{
	if (!check_if_material_number_exists(key))
		throw std::invalid_argument("Material number "s + std::to_string(key) +
			" does not exists. Error in file: " __FILE__);
}


int Material::material_number_counter()
{
	int material_number = ++Material::count;
	bool check = Material::check_if_material_number_exists(material_number);
	while (check) {
		material_number = ++Material::count;
		check = Material::check_if_material_number_exists(material_number);
	}
	return material_number;
}


void Material::set_material_number(int current_value, int new_value)
{
	auto check = check_if_material_number_exists(new_value);

	if ((check && current_value == new_value) || !check) {
		auto new_key = ms_material_map.extract(current_value);
		new_key.key() = new_value;
		ms_material_map.insert(std::move(new_key));
	}
	else {
		throw std::invalid_argument("Material number "s + std::to_string(new_value) +
			" already exists. Error in file: " __FILE__);
	}

	check_value(Parameter::Material_number, new_value);
}


std::pair<double, double> Material::get_min_max(Parameter prop)
{
	double max{}, min{};

	switch (prop) {
	case Parameter::Material_number:
		max = 999.0;
		min = 1.0;
		break;
	case Parameter::Elastic_modulus:
	case Parameter::Shear_modulus:
	case Parameter::Bulk_modulus:
	case Parameter::Lame_constant:
	case Parameter::Specific_weight:
		max = 1.0e12;
		min = 1.0;
		break;
	case Parameter::Poisson_ratio:
		max = 0.5;	// ! 0.49?
		min = 0.0;
		break;
	case Parameter::Elongation_coefficient:
		max = 1.0;
		min = 0.0;
		break;
	case Parameter::Safety_factor:
		max = 1.0e12;
		min = 0.001;
		break;
	case Parameter::Yield_strength:
	case Parameter::Ultimate_strength:
		max = 1.0e12;
		min = 0.0;
		break;
	case Parameter::Friction_angle:
	case Parameter::Cohesion:
		max = 1000.0;
		min = 0.0;
		break;
	case Parameter::Tensile_strength:
		max = 1.0e12;
		min = 0.0;
		break;
	case Parameter::Dilation_angle:
		max = 1.0e12;
		min = -1.0e12;
		break;
	case Parameter::Yield_stress:
	case Parameter::Hardening_modulus:
		max = 1.0e12;
		min = 0.0;
		break;
	}

	return std::minmax(max, min);
}


// Explicit template instantiation
template void Material::check_value(Parameter, int);
template void Material::check_value(Parameter, double);
template void Material::check_value(Parameter, float);
template void Material::check_value(Parameter, unsigned int);

template<typename T>
void Material::check_value(Parameter prop, T value)
{
	auto [min, max] = get_min_max(prop);

	switch (prop) {
	case Parameter::Material_number:
		if (typeid(value) != typeid(int))
			throw std::invalid_argument("Material number must be an integer number ."
				"Error in file: " __FILE__);
		if (value < min || value > max)
			throw std::out_of_range("Invalid material number. Error in file: " __FILE__);
		break;
	case Parameter::Elastic_modulus:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of elastic modulus. Error in file: " __FILE__);
		break;
	case Parameter::Poisson_ratio:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of Poisson's ratio. "
				"The Poisson's ratio must be greater or equal than "s + std::to_string(min) +
				" and less than "s + std::to_string(max) + ". Error in file: " __FILE__);
		break;
	case Parameter::Shear_modulus:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of shear modulus. Error in file: " __FILE__);
		break;
	case Parameter::Bulk_modulus:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of bulk modulus. Error in file: " __FILE__);
		break;
	case Parameter::Lame_constant:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of Lame's constant. Error in file: " __FILE__);
		break;
	case Parameter::Specific_weight:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of specific weight. Error in file: " __FILE__);
		break;
	case Parameter::Elongation_coefficient:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of elongation coefficient. "
				"Error in file: " __FILE__);
		break;
	case Parameter::Safety_factor:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of safety factor. Error in file: " __FILE__);
		break;
	case Parameter::Yield_strength:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of yield strength. Error in file: " __FILE__);
		break;
	case Parameter::Ultimate_strength:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of ultimate strength. Error in file: " __FILE__);
		break;
	case Parameter::Friction_angle:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of friction angle. Error in file: " __FILE__);
		break;
	case Parameter::Cohesion:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of cohesion. Error in file: " __FILE__);
		break;
	case Parameter::Tensile_strength:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of tensile strength. Error in file: " __FILE__);
		break;
	case Parameter::Dilation_angle:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of dilation angle. Error in file: " __FILE__);
		break;
	case Parameter::Yield_stress:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of yield stress. Error in file: " __FILE__);
		break;
	case Parameter::Hardening_modulus:
		if (value < min || value > max)
			throw std::out_of_range("Invalid value of hardening modulus. Error in file: " __FILE__);
		break;
	}
}


var_mat_t Material::material_type(const unsigned int key)
{
	find_material_number(key);
	auto& temp = ms_material_map.find(key)->second;
	var_mat_t w = std::visit([](auto&& arg) -> var_mat_t { return arg; }, temp);
	return w;
}


void Material::set_all_parameters_to_default(const unsigned int key)
{
	auto w = material_type(key);
	std::visit([](auto&& arg) {
		arg.set_elastic_modulus(k_Em, "OFF");
		arg.set_poisson_ratio(k_Pois, "OFF");
		arg.set_shear_modulus(k_Gm, "OFF");
		arg.set_bulk_modulus(k_Km, "OFF");
		arg.set_lame_constant(k_Lam, "OFF");
		arg.set_specific_weight(k_Gam);
		arg.set_elongation_coefficient(k_Alfa);
		arg.set_safety_factor(k_Safe);
		}, w);
}


//auto Material::isotropic_constitutive_matrix(const int key)
//{
//	matrix<double> Dmat(6, 6, 0.0);
//
//	const double Em = elastic_modulus(key);
//	const double ni = poisson_ratio(key);
//
//	// Elements of material matrix
//	double d1 = Em * (1.0 - ni) / ((1.0 + ni) * (1.0 - 2.0 * ni));
//	double d2 = d1 * (1.0 - 2.0 * ni) / (2.0 * (1.0 - ni));
//	double d3 = d1 * ni / (1.0 - ni);
//
//	Dmat(0, 0) = Dmat(1, 1) = Dmat(2, 2) = d1;
//	Dmat(3, 3) = Dmat(4, 4) = Dmat(5, 5) = d2;
//	Dmat(0, 1) = Dmat(0, 2) = Dmat(1, 2) = d3;
//
//	return Dmat;
//}


double Material::elastic_modulus(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_elastic_modulus(); }, w);
	return value;
}


double Material::poisson_ratio(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_poisson_ratio(); }, w);
	return value;
}


double Material::shear_modulus(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_shear_modulus(); }, w);
	return value;
}


double Material::bulk_modulus(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_bulk_modulus(); }, w);
	return value;
}


double Material::lame_constant(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_lame_constant(); }, w);
	return value;
}


double Material::specific_weight(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_specific_weight(); }, w);
	return value;
}


double Material::elongation_coefficient(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_elongation_coefficient(); }, w);
	return value;
}


double Material::safety_factor(const unsigned int key)
{
	auto w = material_type(key);
	double value;
	std::visit([&value](auto&& arg) { value = arg.get_safety_factor(); }, w);
	return value;
}


void Material::check_optional_input_argument_for_elastic_constant(std::string& check)
{
	std::transform(check.begin(), check.end(), check.begin(),
		[](unsigned char c) { return std::toupper(c); });

	if (!(check == "ON" || check == "OFF"))
		throw std::invalid_argument("Invalid argument "s + check + ". "
			"Valid arguments are ON and OFF. Error in file: " __FILE__);
}


void Material::parameters_conversion_for_two_independent_constants(
	Elastic_Constant par1, Elastic_Constant par2, const unsigned int key)
{
	if (par1 == par2)
		throw std::invalid_argument
		("The two input parameters must not be the same. Error in file: " __FILE__);

	auto w = material_type(key);

	switch (par1) {
	case Elastic_Constant::Elastic_modulus:
		switch (par2) {
		case Elastic_Constant::Poisson_ratio:
		{
			double Em, Pois;
			std::visit([&Em](auto&& arg) { Em = arg.get_elastic_modulus(); }, w);
			std::visit([&Pois](auto&& arg) { Pois = arg.get_poisson_ratio(); }, w);

			auto Lame = (Em * k_Pois) / ((1.0 + Pois) * (1.0 - 2.0 * Pois));
			std::visit([&Lame](auto&& arg) { arg.set_lame_constant(Lame, "OFF"); }, w);

			auto Gm = Em / (2.0 + 2.0 * Pois);
			std::visit([&Gm](auto&& arg) { arg.set_shear_modulus(Gm, "OFF"); }, w);

			auto Km = Em / (3.0 - 6.0 * Pois);
			std::visit([&Km](auto&& arg) { arg.set_bulk_modulus(Km, "OFF"); }, w);
			break;
		}
		case Elastic_Constant::Shear_modulus:
		{
			double Em, Gm;
			std::visit([&Em](auto&& arg) { Em = arg.get_elastic_modulus(); }, w);
			std::visit([&Gm](auto&& arg) { Gm = arg.get_shear_modulus(); }, w);

			auto Pois = (Em - 2.0 * Gm) / (2.0 * Gm);
			std::visit([&Pois](auto&& arg) { arg.set_poisson_ratio(Pois, "OFF"); }, w);

			auto Km = (Em * Gm) / (9.0 * Gm - 3.0 * Em);
			std::visit([&Km](auto&& arg) { arg.set_bulk_modulus(Km, "OFF"); }, w);

			auto Lame = (Gm * Em - 2.0 * Gm * Gm) / (3.0 * Gm - Em);
			std::visit([&Lame](auto&& arg) { arg.set_lame_constant(Lame, "OFF"); }, w);
			break;
		}
		case Elastic_Constant::Bulk_modulus:
		{
			double Em, Km;
			std::visit([&Em](auto&& arg) { Em = arg.get_elastic_modulus(); }, w);
			std::visit([&Km](auto&& arg) { Km = arg.get_bulk_modulus(); }, w);

			auto Lame = (9.0 * Km * Km - 3.0 * Km * Em) / (9.0 * Km - Em);
			std::visit([&Lame](auto&& arg) { arg.set_lame_constant(Lame, "OFF"); }, w);

			auto Pois = (3.0 * Km - Em) / (6.0 * Km);
			std::visit([&Pois](auto&& arg) { arg.set_poisson_ratio(Pois, "OFF"); }, w);

			auto Gm = (3.0 * Km * Em) / (9.0 * Km - Em);
			std::visit([&Gm](auto&& arg) { arg.set_shear_modulus(Gm, "OFF"); }, w);
			break;
		}
		case Elastic_Constant::Lame_constant:
		{
			double Em, Lame;
			std::visit([&Em](auto&& arg) { Em = arg.get_elastic_modulus(); }, w);
			std::visit([&Lame](auto&& arg) { Lame = arg.get_lame_constant(); }, w);

			auto R = std::sqrt(Em * Em + 9.0 * Lame * Lame + 2.0 * Em * Lame);

			auto Pois = (2.0 * Lame) / (Em + Lame + R);
			std::visit([&Pois](auto&& arg) { arg.set_poisson_ratio(Pois, "OFF"); }, w);

			auto Gm = (Em - 3.0 * Lame + R) / 4.0;
			std::visit([&Gm](auto&& arg) { arg.set_shear_modulus(Gm, "OFF"); }, w);

			auto Km = (Em + 3.0 * Lame + R) / 6.0;
			std::visit([&Km](auto&& arg) { arg.set_bulk_modulus(Km, "OFF"); }, w);
			break;
		}
		}
		break;
	case Elastic_Constant::Poisson_ratio:
		switch (par2) {
		case Elastic_Constant::Elastic_modulus:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Elastic_modulus, Elastic_Constant::Poisson_ratio, key);
			break;
		case Elastic_Constant::Shear_modulus:
		{
			double Pois, Gm;
			std::visit([&Pois](auto&& arg) { Pois = arg.get_poisson_ratio(); }, w);
			std::visit([&Gm](auto&& arg) { Gm = arg.get_shear_modulus(); }, w);
			
			auto Em = 2.0 * Gm * (1.0 + Pois);
			std::visit([&Em](auto&& arg) { arg.set_elastic_modulus(Em, "OFF"); }, w);

			auto Km = (2.0 * Gm + 2.0 * Gm * Pois) / (3.0 - 6.0 * Pois);
			std::visit([&Km](auto&& arg) { arg.set_bulk_modulus(Km, "OFF"); }, w);

			auto Lame = (2.0 * Gm * Pois) / (1.0 - 2.0 * Pois);
			std::visit([&Lame](auto&& arg) { arg.set_lame_constant(Lame, "OFF"); }, w);
			break;
		}
		case Elastic_Constant::Bulk_modulus:
		{
			double Pois, Km;
			std::visit([&Pois](auto&& arg) { Pois = arg.get_poisson_ratio(); }, w);
			std::visit([&Km](auto&& arg) { Km = arg.get_shear_modulus(); }, w);

			auto Em = 3.0 * Km * (1.0 - 2.0 * Pois);
			std::visit([&Em](auto&& arg) { arg.set_elastic_modulus(Em, "OFF"); }, w);

			auto Gm = (3.0 * Km - 6.0 * Km * Pois) / (2.0 + 2.0 * Pois);
			std::visit([&Gm](auto&& arg) { arg.set_shear_modulus(Gm, "OFF"); }, w);

			auto Lame = (3.0 * Km * Pois) / (1.0 + Pois);
			std::visit([&Lame](auto&& arg) { arg.set_lame_constant(Lame, "OFF"); }, w);
			break;
		}
		case Elastic_Constant::Lame_constant:
		{
			double Pois, Lame;
			std::visit([&Pois](auto&& arg) { Pois = arg.get_poisson_ratio(); }, w);
			std::visit([&Lame](auto&& arg) { Lame = arg.get_lame_constant(); }, w);

			auto Em = ((Lame + Lame * Pois) * (Lame - 2.0 * Lame * Pois)) / Pois;
			std::visit([&Em](auto&& arg) { arg.set_elastic_modulus(Em, "OFF"); }, w);

			auto Gm = (Lame - 2.0 * Lame * Pois) / (2.0 * Pois);
			std::visit([&Gm](auto&& arg) { arg.set_shear_modulus(Gm, "OFF"); }, w);

			auto Km = (Lame + Lame * Pois) / (3.0 * Pois);
			std::visit([&Km](auto&& arg) { arg.set_bulk_modulus(Km, "OFF"); }, w);
			break;
		}
		}
		break;
	case Elastic_Constant::Shear_modulus:
		switch (par2) {
		case Elastic_Constant::Elastic_modulus:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Elastic_modulus, Elastic_Constant::Shear_modulus, key);
			break;
		case Elastic_Constant::Poisson_ratio:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Poisson_ratio, Elastic_Constant::Shear_modulus, key);
			break;
		case Elastic_Constant::Bulk_modulus:
		{
			double Gm, Km;
			std::visit([&Gm](auto&& arg) { Gm = arg.get_shear_modulus(); }, w);
			std::visit([&Km](auto&& arg) { Km = arg.get_bulk_modulus(); }, w);

			auto Em = (9.0 * Km * Gm) / (3.0 * Km + Gm);
			std::visit([&Em](auto&& arg) { arg.set_elastic_modulus(Em, "OFF"); }, w);

			auto Pois = (3.0 * Km - 2.0 * Gm) / (6.0 * Km + 2.0 * Gm);
			std::visit([&Pois](auto&& arg) { arg.set_poisson_ratio(Pois, "OFF"); }, w);

			auto Lame = (3.0 * Km - 2.0 * Gm) / 3.0;
			std::visit([&Lame](auto&& arg) { arg.set_lame_constant(Lame, "OFF"); }, w);
			break;
		}
		case Elastic_Constant::Lame_constant:
		{
			double Gm, Lame;
			std::visit([&Gm](auto&& arg) { Gm = arg.get_shear_modulus(); }, w);
			std::visit([&Lame](auto&& arg) { Lame = arg.get_lame_constant(); }, w);

			auto Em = (3.0 * Gm * Lame + 2.0 * Gm * Gm) / (Lame + Gm);
			std::visit([&Em](auto&& arg) { arg.set_elastic_modulus(Em, "OFF"); }, w);

			auto Pois = Lame / (2.0 * Lame + 2.0 * Gm);
			std::visit([&Pois](auto&& arg) { arg.set_poisson_ratio(Pois, "OFF"); }, w);

			auto Km = (3.0 * Lame + 2.0 * Gm) / 3.0;
			std::visit([&Km](auto&& arg) { arg.set_bulk_modulus(Km, "OFF"); }, w);
			break;
		}
		}
		break;
	case Elastic_Constant::Bulk_modulus:
		switch (par2) {
		case Elastic_Constant::Elastic_modulus:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Elastic_modulus, Elastic_Constant::Bulk_modulus, key);
			break;
		case Elastic_Constant::Poisson_ratio:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Poisson_ratio, Elastic_Constant::Bulk_modulus, key);
			break;
		case Elastic_Constant::Shear_modulus:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Shear_modulus, Elastic_Constant::Bulk_modulus, key);
			break;
		case Elastic_Constant::Lame_constant:
		{
			double Km, Lame;
			std::visit([&Km](auto&& arg) { Km = arg.get_bulk_modulus(); }, w);
			std::visit([&Lame](auto&& arg) { Lame = arg.get_lame_constant(); }, w);

			auto Em = (9.0 * Km * Km - 9.0 * Km * Lame) / (3.0 * Km - Lame);
			std::visit([&Em](auto&& arg) { arg.set_elastic_modulus(Em, "OFF"); }, w);

			auto Pois = Lame / (3.0 * Km - Lame);
			std::visit([&Pois](auto&& arg) { arg.set_poisson_ratio(Pois, "OFF"); }, w);

			auto Gm = 1.5 * (Km - Lame);
			std::visit([&Gm](auto&& arg) { arg.set_shear_modulus(Gm, "OFF"); }, w);
			break;
		}
		}
		break;
	case Elastic_Constant::Lame_constant:
		switch (par2) {
		case Elastic_Constant::Elastic_modulus:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Elastic_modulus, Elastic_Constant::Lame_constant, key);
			break;
		case Elastic_Constant::Poisson_ratio:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Poisson_ratio, Elastic_Constant::Lame_constant, key);
			break;
		case Elastic_Constant::Shear_modulus:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Shear_modulus, Elastic_Constant::Lame_constant, key);
			break;
		case Elastic_Constant::Bulk_modulus:
			parameters_conversion_for_two_independent_constants(
				Elastic_Constant::Bulk_modulus, Elastic_Constant::Lame_constant, key);
			break;
		}
	}
}