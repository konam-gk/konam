#ifndef DRUCKER_PRAGER_H
#define DRUCKER_PRAGER_H


#include "tensor_utilities.h"
#include <string>
#include <optional>


class Drucker_Prager
{
protected:

	Drucker_Prager();


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
	double get_friction_angle() const;
	double get_cohesion() const;
	double get_tensile_strength() const;
	double get_dilation_angle() const;


	void set_material_number(int value);
	void set_elastic_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_poisson_ratio(double value, std::optional<std::string> opt = std::nullopt);
	void set_shear_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_bulk_modulus(double value, std::optional<std::string> opt = std::nullopt);
	void set_lame_constant(double value, std::optional<std::string> opt = std::nullopt);
	void set_specific_weight(double value);
	void set_elongation_coefficient(double value);
	void set_safety_factor(double value);
	void set_title(std::string title);
	void set_friction_angle(double value);
	void set_cohesion(double value);
	void set_tensile_strength(double value);
	void set_dilation_angle(double value);
	void set_all_parameters_to_default();

	double yield_criterion(const std::array<double, 6>& stress);

	//double yield_criterion(const std::array<double, 6>& stress)
	//{
	//	// temporary variables
	//	const auto sigx = stress[0];
	//	const auto sigy = stress[1];
	//	const auto sigz = stress[2];
	//	const auto tauxy = stress[3];
	//	const auto tauyz = stress[4];
	//	const auto tauzx = stress[5];
	//	const auto sigxsigy = sigx - sigy;
	//	const auto sigysigz = sigy - sigz;
	//	const auto sigzsigx = sigz - sigx;
	//	const auto fi = get_friction_angle();
	//	const auto c = get_cohesion();

	//	const auto sx = (2.0 * sigx - sigy - sigz) / 3.0;
	//	const auto sy = (2.0 * sigy - sigz - sigx) / 3.0;
	//	const auto sz = (2.0 * sigz - sigx - sigy) / 3.0;

	//	const auto J3 = sx * sy * sz - sx * tauyz * tauyz - sz * tauzx * tauzx - sz * tauxy * tauxy
	//		+ 2.0 * tauxy * tauyz * tauzx;

	//	// invariants: s, t, theta
	//	const auto s = (sigx + sigy + sigz) / std::sqrt(3.0);
	//	const auto t = std::sqrt(sigxsigy * sigxsigy + sigysigz * sigysigz + sigzsigx * sigzsigx
	//		+ 6.0 * tauxy * tauxy + 6.0 * tauyz * tauyz + 6.0 * tauzx * tauzx) / std::sqrt(3.0);
	//	const auto theta = (1.0 / 3.0) * std::asin((-3.0 * std::sqrt(6.0) * J3) / std::pow(t, 3));

	//	// mean stress
	//	const auto ms = s / std::sqrt(3.0);

	//	// deviatoric stress
	//	const auto ds = std::sqrt(1.5) * t;

	//	// Yield criterion
	//	auto Fdp = ms * std::sin(fi) + ds * (std::cos(theta) / std::sqrt(3.0) - std::sin(theta) * std::sin(fi) / 3.0)
	//		- c * std::cos(fi);

	//	return Fdp;
	//}


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

	// Drucker-Prager Parameters
	double m_friction_angle;
	double m_cohesion;
	double m_tensile_strength;
	double m_dilation_angle;

};


#endif // !DRUCKER_PRAGER_H
