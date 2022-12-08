#ifndef TENSOR_UTILITIES_H
#define TENSOR_UTILITIES_H

#include <array>
#include <cmath>


class Tensor_Utilities
{
public:

	static double invariant_I1(const std::array<double, 6>& stress)
	{
		// Normal and shear components of stresses
		const auto sigx = stress[0];
		const auto sigy = stress[1];
		const auto sigz = stress[2];

		// Cauchy stress tensor principal invariant - I1
		double I1 = (sigx + sigy + sigz);

		return I1;
	}

	static double invariant_I2(const std::array<double, 6>& stress)
	{
		// Normal and shear components of stresses
		const auto sigx = stress[0];
		const auto sigy = stress[1];
		const auto sigz = stress[2];

		// Trace of second-order tensor
		double Tr = sigx + sigy + sigz;
		double Tr2 = (sigx * sigx) + (sigy * sigy) + (sigz * sigz);

		// Cauchy stress tensor principal invariant - I2
		double I2 = 0.5 * (Tr * Tr - Tr2);

		return I2;
	}

	static double invariant_I3(const std::array<double, 6>& stress)
	{
		// Normal and shear components of stresses
		const auto sigx = stress[0];
		const auto sigy = stress[1];
		const auto sigz = stress[2];
		const auto tauxy = stress[3];
		const auto tauyz = stress[4];
		const auto tauzx = stress[5];

		// Cauchy stress tensor principal invariant - I3
		double I3 = sigx * (sigy * sigz - tauyz * tauyz)
			- tauxy * (tauxy * sigz - tauyz * tauzx)
			+ tauzx * (tauxy * tauyz - sigy * tauzx);

		return I3;
	}

	static double invariant_J2(const std::array<double, 6>& stress)
	{
		// Normal and shear components of stresses
		const auto sigx = stress[0];
		const auto sigy = stress[1];
		const auto sigz = stress[2];

		// Trace of second-order tensor
		double Tr = sigx + sigy + sigz;
		double Tr2 = (sigx * sigx) + (sigy * sigy) + (sigz * sigz);

		// Cauchy stress tensor principal invariants
		double I1 = Tr;
		double I2 = 0.5 * (Tr * Tr - Tr2);

		double J2 = (-1.0 / 3.0) * (3.0 * I2 - I1 * I1);

		return J2;
	}

	static double invariant_J3(const std::array<double, 6>& stress)
	{
		// Normal and shear components of stresses
		const auto sigx = stress[0];
		const auto sigy = stress[1];
		const auto sigz = stress[2];
		const auto tauxy = stress[3];
		const auto tauyz = stress[4];
		const auto tauzx = stress[5];

		// Trace of second-order tensor
		double Tr = sigx + sigy + sigz;
		double Tr2 = (sigx * sigx) + (sigy * sigy) + (sigz * sigz);

		// Cauchy stress tensor principal invariants
		double I1 = Tr;
		double I2 = 0.5 * (Tr * Tr - Tr2);
		double I3 = sigx * (sigy * sigz - tauyz * tauyz)
			- tauxy * (tauxy * sigz - tauyz * tauzx)
			+ tauzx * (tauxy * tauyz - sigy * tauzx);

		double J3 = (1.0 / 27.0) * (2.0 * std::pow(I1, 3) - 9.0 * I1 * I2 + 27.0 * I3);

		return J3;
	}

	static double lode_angle(const std::array<double, 6>& stress)
	{
		// Normal and shear components of stresses
		const auto sigx = stress[0];
		const auto sigy = stress[1];
		const auto sigz = stress[2];
		const auto tauxy = stress[3];
		const auto tauyz = stress[4];
		const auto tauzx = stress[5];

		// Trace of second-order tensor
		double Tr = sigx + sigy + sigz;
		double Tr2 = (sigx * sigx) + (sigy * sigy) + (sigz * sigz);

		// Cauchy stress tensor principal invariants
		double I1 = Tr;
		double I2 = 0.5 * (Tr * Tr - Tr2);
		double I3 = sigx * (sigy * sigz - tauyz * tauyz)
			- tauxy * (tauxy * sigz - tauyz * tauzx)
			+ tauzx * (tauxy * tauyz - sigy * tauzx);

		double J2 = (-1.0 / 3.0) * (3.0 * I2 - I1 * I1);
		double J3 = (1.0 / 27.0) * (2.0 * std::pow(I1, 3) - 9.0 * I1 * I2 + 27.0 * I3);

		double lodeAngle = (-3.0 * std::sqrt(3) * J3) / (2.0 * std::sqrt(std::pow(J2, 3)));

		return lodeAngle;
	}

private:

	Tensor_Utilities() = delete;

};

//std::array<double, 3> stress_invariants(const std::array<double, 6>& stress)
//{
//	// Isotropic homogeneous material
//	std::array<double, 3> invariants;
//
//	// Normal and shear components of stresses
//	const auto sigx = stress[0];
//	const auto sigy = stress[1];
//	const auto sigz = stress[2];
//	const auto tauxy = stress[3];
//	const auto tauyz = stress[4];
//	const auto tauzx = stress[5];
//
//	// Trace of second-order tensor
//	double Tr = sigx + sigy + sigz;
//	double Tr2 = (sigx * sigx) + (sigy * sigy) + (sigz * sigz);
//
//	// Cauchy stress tensor principal invariants
//	double I1 = Tr;
//	double I2 = 0.5 * (Tr * Tr - Tr2);
//	double I3 = sigx * (sigy * sigz - tauyz * tauyz)
//		- tauxy * (tauxy * sigz - tauyz * tauzx)
//		+ tauzx * (tauxy * tauyz - sigy * tauzx);
//
//	double J2 = (-1.0 / 3.0) * (3.0 * I2 - I1 * I1);
//	double J3 = (1.0 / 27.0) * (2.0 * std::pow(I1, 3) - 9.0 * I1 * I2 + 27.0 * I3);
//	double lode_angle = (-3.0 * std::sqrt(3) * J3) / (2.0 * std::sqrt(std::pow(J2, 3)));
//
//	invariants[0] = I1;
//	invariants[1] = J2;
//	invariants[3] = lode_angle;
//
//	return invariants;
//}

#endif // !TENSOR_UTILITIES_H
