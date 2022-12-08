#ifndef CONCRETE_H
#define CONCRETE_H


#include <string>
#include <optional>
#include <utility>	// std::pair
#include <vector>


class Concrete
{
public:

	enum class Class { C12, C16, C20, C25, C30, C35, C40, C45, C50, C55, C60, C70, C80, C90 };


protected:

	Concrete(Concrete::Class type);


public:

	int get_material_number() const;
	double get_elastic_modulus() const;
	double get_poisson_ratio() const;
	double get_shear_modulus() const;
	double get_bulk_modulus() const;
	double get_specific_weight() const;
	double get_elongation_coefficient() const;
	double get_safety_factor() const;
	std::string get_type() const;
	double get_acc() const;
	double get_compressive_strength() const;
	double get_tensile_strength() const;
	double get_strain_at_peak_stress() const;
	double get_ultimate_strain() const;
	double compressive_stress_at_deformation(const double value);

	// set General properties
	void set_elastic_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_poisson_ratio(double value, std::optional<std::string> opt = std::nullopt);
	void set_shear_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_bulk_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_specific_weight(double value);
	void set_elongation_coefficient(double value);
	void set_safety_factor(double value);
	void set_type(Concrete::Class type);
	void set_parameters(Concrete::Class type);

	// set Strength (General)
	void set_acc(double value);
	void set_compressive_strength(double value);
	void set_tensile_strength(double value);


private:

	// Material Parameters
	static inline unsigned int m_material_number{};
	double m_elastic_modulus;
	double m_poisson_ratio;
	double m_shear_modulus;
	double m_bulk_modulus;
	double m_specific_weight;
	double m_elongation_coefficient;
	double m_safety_factor;
	std::string m_type;
	double m_strain_at_peak_stress;		// compressive strain at the peak stress fc
	double m_ultimate_strain;
	double m_acc;
	double m_compressive_strength;
	double m_tensile_strength;

	inline void save_in_container();

	enum class Strength {
		ACC_coefficient, Compressive_strength, Tensile_strength
	};


	inline std::pair<double, double> get_min_max(Strength prop);
	inline void check_strength_value(Strength prop, double value);

};


#endif // !CONCRETE_H

