#ifndef MATERIAL_H
#define MATERIAL_H


#include <map>
#include <stdexcept>
#include <variant>
#include <memory>
#include <algorithm>	// std::transform

#include "mohr_coulomb.h"
#include "elastic_material.h"
#include "von_mises.h"
#include "drucker_prager.h"
#include "concrete.h"
#include "rsteel.h"


using namespace std::string_literals;

using var_mat_t = std::variant<Elastic_Material, Mohr_Coulomb, Von_Mises, Drucker_Prager>;
//using var_mat_t = std::variant<Concrete, Elastic_Material, Mohr_Coulomb, Von_Mises, Drucker_Prager>;


class Material
{
private:

	Material() = delete;

	friend class Mohr_Coulomb;
	friend class Elastic_Material;
	friend class Von_Mises;
	friend class Drucker_Prager;
	friend class Concrete;
	friend class RSteel;


	// map container of materials
	static inline std::map<unsigned int, var_mat_t> ms_material_map;

	template<typename T>
	static inline void insert(const int num, T& material)
	{
		auto pr = ms_material_map.emplace(num, material);
		if (!pr.second)
			throw std::invalid_argument("Material number "s + std::to_string(num) + " already exists. Error in file: " __FILE__);
	}


	// Default Parameters
	static const int k_num = 1;	                                         // default material number
	static constexpr double k_Em = 30000.0;                              // default Young's modulus
	static constexpr double k_Pois = 0.2;                                // default Poisson's ratio
	static constexpr double k_Gm = k_Em / (2.0 * (1.0 + k_Pois));        // default shear modulus
	static constexpr double k_Km = k_Em / (3.0 * (1.0 - 2.0 * k_Pois));  // default bulk modulus
	static constexpr double k_Lam = (k_Em * k_Pois) / ((1.0 + k_Pois) *  // default Lame's first parameter
		(1.0 - 2.0 * k_Pois));
	static constexpr double k_Gam = 20.0;                                // default specific weight
	static constexpr double k_Alfa = 1.0e-5;                             // default elongatio coefficient
	static constexpr double k_Safe = 1.0;                                // default safety factor

	enum class Parameter {
		Material_number, Elastic_modulus, Poisson_ratio, Shear_modulus, Bulk_modulus,
		Lame_constant, Specific_weight, Elongation_coefficient, Safety_factor,
		Yield_strength, Ultimate_strength, Friction_angle, Cohesion, Tensile_strength, Dilation_angle,
		Yield_stress, Hardening_modulus
	};

	enum class Elastic_Constant {
		Elastic_modulus, Poisson_ratio, Shear_modulus, Bulk_modulus, Lame_constant
	};

	enum class Hardening { Isotropic, Kinematic, Mixed };

	static bool check_if_material_number_exists(int key);

	static int material_number_counter();

	static void set_material_number(int current_value, int new_value);

	static inline unsigned int count{};

	static std::pair<double, double> get_min_max(Parameter prop);

	template<typename T> static void check_value(Parameter prop, T value);

	static var_mat_t material_type(const unsigned int key);

	static void set_all_parameters_to_default(const unsigned int key);

	static void check_optional_input_argument_for_elastic_constant(std::string& check);

	static void parameters_conversion_for_two_independent_constants(
		Elastic_Constant par1, Elastic_Constant par2, const unsigned int key);


public:

	static std::unique_ptr<Elastic_Material> Elastic_Material();
	static std::unique_ptr<Mohr_Coulomb> Mohr_Coulomb();

	static double elastic_modulus(const unsigned int key);
	static double poisson_ratio(const unsigned int key);
	static double shear_modulus(const unsigned int key);
	static double bulk_modulus(const unsigned int key);
	static double lame_constant(const unsigned int key);
	static double specific_weight(const unsigned int key);
	static double elongation_coefficient(const unsigned int key);
	static double safety_factor(const unsigned int key);
	static void find_material_number(int key);

};



#endif // !MATERIAL_H