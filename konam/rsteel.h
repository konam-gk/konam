#ifndef RSTEEL_H
#define RSTEEL_H


#include <string>
#include <optional>


class RSteel
{
public:

	enum class Class {
		B220A, B220B, B220C, B450A, B450B, B450C, B500A, B500B, B500C,
		B550B, B600B, B670B
	};


protected:

	RSteel(RSteel::Class type);


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

	// set General properties
	void set_elastic_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_poisson_ratio(double value, std::optional<std::string> opt = std::nullopt);
	void set_shear_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_bulk_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_specific_weight(double value);
	void set_elongation_coefficient(double value);
	void set_safety_factor(double value);
	void set_type(RSteel::Class type);
	void set_parameters(RSteel::Class type);

	// set Strength (General)
	void set_yield_strength(double value);
	void set_ultimate_strength(double value);
	void set_strain_at_yield_strength(double value);
	void set_ultimate_strain(double value);


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

	double m_yield_strength;
	double m_ultimate_strength;
	double m_strain_at_yield_strength;
	double m_ultimate_strain;


	inline void save_in_container();

	enum class Strength {
		Yield_strength, Ultimate_strength, Strain_at_yield_strength, Ultimate_strain
	};


	inline std::pair<double, double> get_min_max(RSteel::Strength prop);
	inline void check_strength_value(Strength prop, double value);

};


#endif // !RSTEEL_H