#ifndef ELASTIC_MATERIAL_H
#define ELASTIC_MATERIAL_H


#include "tensor_utilities.h"
#include <string>
#include <optional>


class Elastic_Material
{
protected:

	Elastic_Material();


public:

	int get_material_number() const;
	double get_elastic_modulus() const;
	double get_poisson_ratio() const;
	double get_shear_modulus() const;
	double get_bulk_modulus() const;
	double get_lame_constant() const;
	double get_specific_weight() const;
	double get_elongation_coefficient() const;
	double get_safety_factor() const;
	std::string get_title() const;
	double get_yield_strength() const;
	double get_ultimate_strength() const;

	void set_material_number(unsigned int value);
	void set_elastic_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_poisson_ratio(double value, std::optional<std::string> opt = std::nullopt);
	void set_shear_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_bulk_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_lame_constant(double value, std::optional<std::string> opt = std::nullopt);
	void set_specific_weight(double value);
	void set_elongation_coefficient(double value);
	void set_safety_factor(double value);
	void set_title(std::string title);
	void set_yield_strength(double value);
	void set_ultimate_strength(double value);
	void set_all_parameters_to_default();


private:

	// Material Parameters
	int m_material_number;
	double m_elastic_modulus;
	double m_poisson_ratio;
	double m_shear_modulus;
	double m_bulk_modulus;
	double m_lame_constant;
	double m_specific_weight;
	double m_elongation_coefficient;
	double m_safety_factor;
	std::string m_title;

	// Elastic-Material Parameters
	double m_yield_strength;
	double m_ultimate_strength;

};


#endif // !ELASTIC_MATERIAL_H