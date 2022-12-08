#ifndef HEXAHEDRON_SHAPE_FUNCTIONS_DERIVATIVES_H
#define HEXAHEDRON_SHAPE_FUNCTIONS_DERIVATIVES_H


#include <stdexcept>

#include "konam_array.h"


template<unsigned int NVT>
// NVT - number of element vertices
auto hexahedron_shape_functions_derivatives(const konam_mat& abscissa, const int i)
{
	konam_mat func(3, NVT);

	// natural coordinates
	auto xi = abscissa(i, 0);
	auto eta = abscissa(i, 1);
	auto zeta = abscissa(i, 2);

	switch (NVT) {
	case 8:
		// vertex 0
		func(0, 0) = -0.125 * (1.0 - eta) * (1.0 - zeta);
		func(1, 0) = -0.125 * (1.0 - xi) * (1.0 - zeta);
		func(2, 0) = -0.125 * (1.0 - xi) * (1.0 - eta);
		// vertex 1
		func(0, 1) = +0.125 * (1.0 - eta) * (1.0 - zeta);
		func(1, 1) = -0.125 * (1.0 + xi) * (1.0 - zeta);
		func(2, 1) = -0.125 * (1.0 + xi) * (1.0 - eta);
		// vertex 2
		func(0, 2) = +0.125 * (1.0 + eta) * (1.0 - zeta);
		func(1, 2) = +0.125 * (1.0 + xi) * (1.0 - zeta);
		func(2, 2) = -0.125 * (1.0 + xi) * (1.0 + eta);
		// vertex 3
		func(0, 3) = -0.125 * (1.0 + eta) * (1.0 - zeta);
		func(1, 3) = +0.125 * (1.0 - xi) * (1.0 - zeta);
		func(2, 3) = -0.125 * (1.0 - xi) * (1.0 + eta);
		// vertex 4
		func(0, 4) = -0.125 * (1.0 - eta) * (1.0 + zeta);
		func(1, 4) = -0.125 * (1.0 - xi) * (1.0 + zeta);
		func(2, 4) = +0.125 * (1.0 - xi) * (1.0 - eta);
		// vertex 5
		func(0, 5) = +0.125 * (1.0 - eta) * (1.0 + zeta);
		func(1, 5) = -0.125 * (1.0 + xi) * (1.0 + zeta);
		func(2, 5) = +0.125 * (1.0 + xi) * (1.0 - eta);
		// vertex 6
		func(0, 6) = +0.125 * (1.0 + eta) * (1.0 + zeta);
		func(1, 6) = +0.125 * (1.0 + xi) * (1.0 + zeta);
		func(2, 6) = +0.125 * (1.0 + xi) * (1.0 + eta);
		// vertex 7
		func(0, 7) = -0.125 * (1.0 + eta) * (1.0 + zeta);
		func(1, 7) = +0.125 * (1.0 - xi) * (1.0 + zeta);
		func(2, 7) = +0.125 * (1.0 - xi) * (1.0 + eta);
		break;
	case 20:	// preveri
	{
		auto deriv = [&xi, &eta, &zeta](char coord, int vertex, double i, double j, double k) {
			double shape{};
			auto xi2 = xi * xi;
			auto eta2 = eta * eta;
			auto zeta2 = zeta * zeta;

			switch (vertex) {
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				switch (coord) {
				case 'x':
					shape = 0.125 * (1.0 + j * eta) * (1.0 + k * zeta) * (i * (i * xi + j * eta + k * zeta - 2.0) + i * (1.0 + i * xi));
					break;
				case 'y':
					shape = 0.125 * (1.0 + i * xi) * (1.0 + k * zeta) * (2.0 * j * j * eta - j + i * j * xi + j * k * zeta);
					break;
				case 'z':
					shape = 0.125 * (1.0 + i * xi) * (1.0 + j * eta) * (2.0 * k * k * zeta - k + i * k * xi + j * k * eta);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 13: case 15: case 17: case 19:
				switch (coord) {
				case 'x':
					shape = -0.5 * xi * (1.0 + j * eta) * (1.0 + k * zeta);
					break;
				case 'y':
					shape = 0.25 * j * (1.0 - xi2) * (1.0 + k * zeta);
					break;
				case 'z':
					shape = 0.25 * k * (1.0 - xi2) * (1.0 + j * eta);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 14: case 16: case 18: case 20:
				switch (coord) {
				case 'x':
					shape = 0.25 * i * (1.0 - eta2) * (1.0 + k * zeta);
					break;
				case 'y':
					shape = -0.5 * eta * (1.0 + k * zeta) * (1.0 + i * xi);
					break;
				case 'z':
					shape = 0.25 * k * (1.0 - eta2) * (1.0 + i * xi);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 9: case 10: case 11: case 12:
				switch (coord) {
				case 'x':
					shape = 0.25 * i * (1.0 - zeta2) * (1.0 + j * eta);
					break;
				case 'y':
					shape = 0.25 * j * (1.0 - zeta2) * (1.0 + i * xi);
					break;
				case 'z':
					shape = -0.5 * zeta * (1.0 + j * eta) * (1.0 + i * xi);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			default:
				throw std::out_of_range("Error in file " __FILE__);
			}
			return shape;
		};

		// vertex 0
		func(0, 0) = deriv('x', 1, -1, -1, -1);
		func(1, 0) = deriv('y', 1, -1, -1, -1);
		func(2, 0) = deriv('z', 1, -1, -1, -1);
		// vertex 1
		func(0, 1) = deriv('x', 3, 1, -1, -1);
		func(1, 1) = deriv('y', 3, 1, -1, -1);
		func(2, 1) = deriv('z', 3, 1, -1, -1);
		// vertex 2
		func(0, 2) = deriv('x', 5, 1, 1, -1);
		func(1, 2) = deriv('y', 5, 1, 1, -1);
		func(2, 2) = deriv('z', 5, 1, 1, -1);
		// vertex 3
		func(0, 3) = deriv('x', 7, -1, 1, -1);
		func(1, 3) = deriv('y', 7, -1, 1, -1);
		func(2, 3) = deriv('z', 7, -1, 1, -1);
		// vertex 4
		func(0, 4) = deriv('x', 13, -1, -1, 1);
		func(1, 4) = deriv('y', 13, -1, -1, 1);
		func(2, 4) = deriv('z', 13, -1, -1, 1);
		// vertex 5
		func(0, 5) = deriv('x', 15, 1, -1, 1);
		func(1, 5) = deriv('y', 15, 1, -1, 1);
		func(2, 5) = deriv('z', 15, 1, -1, 1);
		// vertex 6
		func(0, 6) = deriv('x', 17, 1, 1, 1);
		func(1, 6) = deriv('y', 17, 1, 1, 1);
		func(2, 6) = deriv('z', 17, 1, 1, 1);
		// vertex 7
		func(0, 7) = deriv('x', 19, -1, 1, 1);
		func(1, 7) = deriv('y', 19, -1, 1, 1);
		func(2, 7) = deriv('z', 19, -1, 1, 1);
		// vertex 8
		func(0, 8) = deriv('x', 9, -1, -1, 0);
		func(1, 8) = deriv('y', 9, -1, -1, 0);
		func(2, 8) = deriv('z', 9, -1, -1, 0);
		// vertex 9
		func(0, 9) = deriv('x', 10, 1, -1, 0);
		func(1, 9) = deriv('y', 10, 1, -1, 0);
		func(2, 9) = deriv('z', 10, 1, -1, 0);
		// vertex 10
		func(0, 10) = deriv('x', 11, 1, 1, 0);
		func(1, 10) = deriv('y', 11, 1, 1, 0);
		func(2, 10) = deriv('z', 11, 1, 1, 0);
		// vertex 11
		func(0, 11) = deriv('x', 12, -1, 1, 0);
		func(1, 11) = deriv('y', 12, -1, 1, 0);
		func(2, 11) = deriv('z', 12, -1, 1, 0);
		// vertex 12
		func(0, 12) = deriv('x', 2, 0, -1, -1);
		func(1, 12) = deriv('y', 2, 0, -1, -1);
		func(2, 12) = deriv('z', 2, 0, -1, -1);
		// vertex 13
		func(0, 13) = deriv('x', 4, 1, 0, -1);
		func(1, 13) = deriv('y', 4, 1, 0, -1);
		func(2, 13) = deriv('z', 4, 1, 0, -1);
		// vertex 14
		func(0, 14) = deriv('x', 6, 0, 1, -1);
		func(1, 14) = deriv('y', 6, 0, 1, -1);
		func(2, 14) = deriv('z', 6, 0, 1, -1);
		// vertex 15
		func(0, 15) = deriv('x', 8, -1, 0, -1);
		func(1, 15) = deriv('y', 8, -1, 0, -1);
		func(2, 15) = deriv('z', 8, -1, 0, -1);
		// vertex 16
		func(0, 16) = deriv('x', 14, 0, -1, 1);
		func(1, 16) = deriv('y', 14, 0, -1, 1);
		func(2, 16) = deriv('z', 14, 0, -1, 1);
		// vertex 17
		func(0, 17) = deriv('x', 16, 1, 0, 1);
		func(1, 17) = deriv('y', 16, 1, 0, 1);
		func(2, 17) = deriv('z', 16, 1, 0, 1);
		// vertex 18
		func(0, 18) = deriv('x', 18, 0, 1, 1);
		func(1, 18) = deriv('y', 18, 0, 1, 1);
		func(2, 18) = deriv('z', 18, 0, 1, 1);
		// vertex 19
		func(0, 19) = deriv('x', 20, -1, 0, 1);
		func(1, 19) = deriv('y', 20, -1, 0, 1);
		func(2, 19) = deriv('z', 20, -1, 0, 1);
		break;
	}
	case 27:	// preveri
	{
		auto deriv = [&xi, &eta, &zeta](char coord, int vertex, double i, double j, double k) {
			double shape{};
			auto xi2 = xi * xi;
			auto eta2 = eta * eta;
			auto zeta2 = zeta * zeta;

			switch (vertex) {
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				switch (coord) {
				case 'x':
					shape = 0.125 * (eta2 + eta * j) * (zeta2 + zeta * k) * (2.0 * xi + i);
					break;
				case 'y':
					shape = 0.125 * (xi2 + xi * i) * (zeta2 + zeta * k) * (2.0 * eta + j);
					break;
				case 'z':
					shape = 0.125 * (xi2 + xi * i) * (eta2 + eta * j) * (2.0 * zeta + k);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 13: case 14: case 15: case 16: case 9: case 10: case 11: case 12:
			case 17: case 18: case 19: case 20:
				switch (coord) {
				case 'x':
					shape = 2.0 * eta2 * xi + 0.5 * j * j * eta2 * zeta2 * xi + 0.5 * j * j * j * eta * xi
						- 2.0 * xi - 0.5 * j * j * eta2 * xi - 0.5 * j * j * j * eta * zeta2 * xi +
						i * (1.0 - eta2 + 0.25 * j * j * eta2 - 0.25 * j * j * j * eta - 0.25 * j * j * eta2 * zeta2
							+ 0.25 * j * j * j * eta * zeta2);
					break;
				case 'y':
					shape = 2.0 * eta * xi2 + 0.25 * j * j * j * xi2 + 0.5 * j * j * eta * zeta2 * xi2
						- 0.5 * j * j * eta * xi2 - 0.25 * j * j * j * zeta2 * xi2
						- 0.5 * j * j * eta * std::pow(zeta2, 3) + 0.5 * j * j * k * eta * std::pow(zeta, 5)
						+ 0.25 * j * j * j * std::pow(zeta2, 3) - 0.25 * j * j * j * k * std::pow(zeta, 5)
						+ 0.5 * j * j * eta * std::pow(zeta2, 2) - 0.5 * j * j * k * eta * std::pow(zeta, 3)
						- 0.25 * j * j * j * std::pow(zeta2, 2) + 0.25 * j * j * j * k * std::pow(zeta, 3)
						+ i * (-0.25 * j * j * j * xi - 2.0 * eta * xi + 0.25 * j * j * j * zeta2 * xi
							+ 0.5 * j * j * eta * xi - 0.5 * j * j * eta * zeta2 * xi);
					break;
				case 'z':
					shape = 0.5 * j * j * eta2 * zeta * xi2 - 0.5 * j * j * j * eta * zeta * xi2
						- 1.5 * j * j * eta2 * std::pow(zeta, 5) + 1.25 * j * j * k * eta2 * std::pow(zeta2, 2)
						+ j * j * eta2 * std::pow(zeta, 3) - 0.75 * j * j * k * eta2 * zeta2
						+ 1.5 * j * j * j * eta * std::pow(zeta, 5) - 1.25 * j * j * j * k * eta * std::pow(zeta2, 2)
						- j * j * j * eta * std::pow(zeta, 3) + 0.75 * j * j * j * k * eta * zeta2 + 0.5 * k * k * zeta
						- 0.25 * k * k * k + i * (-0.5 * j * j * eta2 * zeta * xi + 0.5 * j * j * j * eta * zeta * xi);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 25: case 21: case 22: case 23: case 24: case 26:
				switch (coord) {
				case 'x':
					shape = -xi * zeta - k * xi * zeta2 + xi * eta2 * zeta + k * xi * eta2 * zeta2 + 0.5
						- 0.5 * zeta2 - 0.5 * eta2 + 0.5 * eta2 * zeta2 - xi * eta - j * xi * eta2 +
						xi * eta * zeta2 + j * xi * eta2 * zeta2
						+ i * (xi - xi * eta2 - xi * zeta2 + xi * eta2 * zeta2);
					break;
				case 'y':
					shape = -eta * zeta - k * eta * zeta2 + xi2 * eta * zeta + k * xi2 * eta * zeta2 - xi * eta
						+ xi * eta * zeta2 + 0.5 + j * eta - 0.5 * zeta2 - j * eta * zeta2 - 0.5 * xi2 -
						j * xi2 * eta + 0.5 * xi2 * zeta2 + j * xi2 * eta * zeta2
						+ i * (-xi2 * eta + xi2 * eta * zeta2);
					break;
				case 'z':
					shape = 0.5 + k * zeta - 0.5 * eta2 - k * eta2 * zeta - 0.5 * xi2 - k * xi2 * zeta
						+ 0.5 * xi2 * eta2 + k * xi2 * eta2 * zeta - xi * zeta + xi * eta2 * zeta
						- eta * zeta - j * eta2 * zeta + xi2 * eta * zeta + j * xi2 * eta2 * zeta
						+ i * (-xi2 * zeta + xi2 * eta2 * zeta);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 27:
				switch (coord) {
				case 'x':
					shape = -2.0 * xi * (1.0 - eta2) * (1.0 - zeta2);
					break;
				case 'y':
					shape = -2.0 * eta * (1.0 - xi2) * (1.0 - zeta2);
					break;
				case 'z':
					shape = -2.0 * zeta * (1.0 - xi2) * (1.0 - eta2);
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			default:
				throw std::out_of_range("Error in file " __FILE__);
			}
			return shape;
		};

		// vertex 0
		func(0, 0) = deriv('x', 1, -1, -1, -1);
		func(1, 0) = deriv('y', 1, -1, -1, -1);
		func(2, 0) = deriv('z', 1, -1, -1, -1);
		// vertex 1
		func(0, 1) = deriv('x', 3, 1, -1, -1);
		func(1, 1) = deriv('y', 3, 1, -1, -1);
		func(2, 1) = deriv('z', 3, 1, -1, -1);
		// vertex 2
		func(0, 2) = deriv('x', 5, 1, 1, -1);
		func(1, 2) = deriv('y', 5, 1, 1, -1);
		func(2, 2) = deriv('z', 5, 1, 1, -1);
		// vertex 3
		func(0, 3) = deriv('x', 7, -1, 1, -1);
		func(1, 3) = deriv('y', 7, -1, 1, -1);
		func(2, 3) = deriv('z', 7, -1, 1, -1);
		// vertex 4
		func(0, 4) = deriv('x', 19, -1, -1, 1);
		func(1, 4) = deriv('y', 19, -1, -1, 1);
		func(2, 4) = deriv('z', 19, -1, -1, 1);
		// vertex 5
		func(0, 5) = deriv('x', 21, 1, -1, 1);
		func(1, 5) = deriv('y', 21, 1, -1, 1);
		func(2, 5) = deriv('z', 21, 1, -1, 1);
		// vertex 6
		func(0, 6) = deriv('x', 23, 1, 1, 1);
		func(1, 6) = deriv('y', 23, 1, 1, 1);
		func(2, 6) = deriv('z', 23, 1, 1, 1);
		// vertex 7
		func(0, 7) = deriv('x', 25, -1, 1, 1);
		func(1, 7) = deriv('y', 25, -1, 1, 1);
		func(2, 7) = deriv('z', 25, -1, 1, 1);
		// vertex 8
		func(0, 8) = deriv('x', 10, -1, -1, 0);
		func(1, 8) = deriv('y', 10, -1, -1, 0);
		func(2, 8) = deriv('z', 10, -1, -1, 0);
		// vertex 9
		func(0, 9) = deriv('x', 12, 1, -1, 0);
		func(1, 9) = deriv('y', 12, 1, -1, 0);
		func(2, 9) = deriv('z', 12, 1, -1, 0);
		// vertex 10
		func(0, 10) = deriv('x', 14, 1, 1, 0);
		func(1, 10) = deriv('y', 14, 1, 1, 0);
		func(2, 10) = deriv('z', 14, 1, 1, 0);
		// vertex 11
		func(0, 11) = deriv('x', 16, -1, 1, 0);
		func(1, 11) = deriv('y', 16, -1, 1, 0);
		func(2, 11) = deriv('z', 16, -1, 1, 0);
		// vertex 12
		func(0, 12) = deriv('x', 2, 0, -1, -1);
		func(1, 12) = deriv('y', 2, 0, -1, -1);
		func(2, 12) = deriv('z', 2, 0, -1, -1);
		// vertex 13
		func(0, 13) = deriv('x', 4, 1, 0, -1);
		func(1, 13) = deriv('y', 4, 1, 0, -1);
		func(2, 13) = deriv('z', 4, 1, 0, -1);
		// vertex 14
		func(0, 14) = deriv('x', 6, 0, 1, -1);
		func(1, 14) = deriv('y', 6, 0, 1, -1);
		func(2, 14) = deriv('z', 6, 0, 1, -1);
		// vertex 15
		func(0, 15) = deriv('x', 8, -1, 0, -1);
		func(1, 15) = deriv('y', 8, -1, 0, -1);
		func(2, 15) = deriv('z', 8, -1, 0, -1);
		// vertex 16
		func(0, 16) = deriv('x', 20, 0, -1, 1);
		func(1, 16) = deriv('y', 20, 0, -1, 1);
		func(2, 16) = deriv('z', 20, 0, -1, 1);
		// vertex 17
		func(0, 17) = deriv('x', 22, 1, 0, 1);
		func(1, 17) = deriv('y', 22, 1, 0, 1);
		func(2, 17) = deriv('z', 22, 1, 0, 1);
		// vertex 18
		func(0, 18) = deriv('x', 24, 0, 1, 1);
		func(1, 18) = deriv('y', 24, 0, 1, 1);
		func(2, 18) = deriv('z', 24, 0, 1, 1);
		// vertex 19
		func(0, 19) = deriv('x', 26, -1, 0, 1);
		func(1, 19) = deriv('y', 26, -1, 0, 1);
		func(2, 19) = deriv('z', 26, -1, 0, 1);
		// vertex 20
		func(0, 20) = deriv('x', 11, 0, -1, 0);
		func(1, 20) = deriv('y', 11, 0, -1, 0);
		func(2, 20) = deriv('z', 11, 0, -1, 0);
		// vertex 21
		func(0, 21) = deriv('x', 13, 1, 0, 0);
		func(1, 21) = deriv('y', 13, 1, 0, 0);
		func(2, 21) = deriv('z', 13, 1, 0, 0);
		// vertex 22
		func(0, 22) = deriv('x', 15, 0, 1, 0);
		func(1, 22) = deriv('y', 15, 0, 1, 0);
		func(2, 22) = deriv('z', 15, 0, 1, 0);
		// vertex 23
		func(0, 23) = deriv('x', 17, -1, 0, 0);
		func(1, 23) = deriv('y', 17, -1, 0, 0);
		func(2, 23) = deriv('z', 17, -1, 0, 0);
		// vertex 24
		func(0, 24) = deriv('x', 9, 0, 0, -1);
		func(1, 24) = deriv('y', 9, 0, 0, -1);
		func(2, 24) = deriv('z', 9, 0, 0, -1);
		// vertex 25
		func(0, 25) = deriv('x', 27, 0, 0, 1);
		func(1, 25) = deriv('y', 27, 0, 0, 1);
		func(2, 25) = deriv('z', 27, 0, 0, 1);
		// vertex 26
		func(0, 26) = deriv('x', 18, 0, 0, 0);
		func(1, 26) = deriv('y', 18, 0, 0, 0);
		func(2, 26) = deriv('z', 18, 0, 0, 0);
		break;
	}
	case 32:	// preveri
	{
		auto deriv = [&xi, &eta, &zeta](char coord, int vertex, double i, double j, double k) {
			double shape{};
			auto xi2 = xi * xi;
			auto eta2 = eta * eta;
			auto zeta2 = zeta * zeta;

			switch (vertex) {
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				switch (coord) {
				case 'x':
					shape = (9.0 / 64.0) * (1.0 + eta * j) * (1.0 + zeta * k) * (i * ((-19.0 / 9.0) + xi2 + eta2 + zeta2)
						+ 2.0 * xi * (1.0 + xi * i));
					break;
				case 'y':
					shape = (9.0 / 64.0) * (1.0 + xi * i) * (1.0 + zeta * k) * (j * ((-19.0 / 9.0) + xi2 + eta2 + zeta2)
						+ 2.0 * eta * (1.0 + eta * j));
					break;
				case 'z':
					shape = (9.0 / 64.0) * (1.0 + xi * i) * (1.0 + eta * j) * (k * ((-19.0 / 9.0) + xi2 + eta2 + zeta2)
						+ 2.0 * zeta * (1.0 + zeta * k));
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 17: case 18: case 21: case 22: case 25: case 26: case 29: case 30:
				switch (coord) {
				case 'x':
					shape = (81.0 / 64.0) * (1.0 + eta * j) * (1.0 + zeta * k) * ((-2.0 * xi) * (1.0 / 9.0 + xi * i) + i * (1.0 - xi2));
					break;
				case 'y':
					shape = (81.0 / 64.0) * (1.0 - xi2) * (1.0 / 9.0 + xi * i) * (1.0 + zeta * k) * j;
					break;
				case 'z':
					shape = (81.0 / 64.0) * (1.0 - xi2) * (1.0 / 9.0 + xi * i) * (1.0 + eta * j) * k;
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 19: case 20: case 23: case 24: case 27: case 28: case 31: case 32:
				switch (coord) {
				case 'x':
					shape = (81.0 / 64.0) * (1.0 - eta2) * (1.0 / 9.0 + eta * j) * (1.0 + zeta * k) * i;
					break;
				case 'y':
					shape = (81.0 / 64.0) * (1.0 + xi * i) * (1.0 + zeta * k) * ((-2.0 * eta) * (1.0 / 9.0 + eta * j) + j * (1.0 - eta2));
					break;
				case 'z':
					shape = (81.0 / 64.0) * (1.0 + xi * i) * (1.0 - eta2) * (1.0 / 9.0 + eta * j) * k;
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
				switch (coord) {
				case 'x':
					shape = (81.0 / 64.0) * (1.0 + eta * j) * (1.0 / 9.0 + zeta * k) * (1.0 - zeta2) * i;
					break;
				case 'y':
					shape = (81.0 / 64.0) * (1.0 + xi * i) * (1.0 / 9.0 + zeta * k) * (1.0 - zeta2) * j;
					break;
				case 'z':
					shape = (81.0 / 64.0) * (1.0 + xi * i) * (1.0 + eta * j) * (k * (1.0 - zeta2) - 2.0 * zeta * (1.0 / 9.0 + zeta * k));
					break;
				default:
					throw std::invalid_argument("Error in file " __FILE__);
				}
				break;
			default:
				throw std::out_of_range("Error in file " __FILE__);
			}
			return shape;
		};

		// vertex 0
		func(0, 0) = deriv('x', 1, -1, -1, -1);
		func(1, 0) = deriv('y', 1, -1, -1, -1);
		func(2, 0) = deriv('z', 1, -1, -1, -1);
		// vertex 1
		func(0, 1) = deriv('x', 4, 1, -1, -1);
		func(1, 1) = deriv('y', 4, 1, -1, -1);
		func(2, 1) = deriv('z', 4, 1, -1, -1);
		// vertex 2
		func(0, 2) = deriv('x', 7, 1, 1, -1);
		func(1, 2) = deriv('y', 7, 1, 1, -1);
		func(2, 2) = deriv('z', 7, 1, 1, -1);
		// vertex 3
		func(0, 3) = deriv('x', 10, -1, 1, -1);
		func(1, 3) = deriv('y', 10, -1, 1, -1);
		func(2, 3) = deriv('z', 10, -1, 1, -1);
		// vertex 4
		func(0, 4) = deriv('x', 21, -1, -1, 1);
		func(1, 4) = deriv('y', 21, -1, -1, 1);
		func(2, 4) = deriv('z', 21, -1, -1, 1);
		// vertex 5
		func(0, 5) = deriv('x', 24, 1, -1, 1);
		func(1, 5) = deriv('y', 24, 1, -1, 1);
		func(2, 5) = deriv('z', 24, 1, -1, 1);
		// vertex 6
		func(0, 6) = deriv('x', 27, 1, 1, 1);
		func(1, 6) = deriv('y', 27, 1, 1, 1);
		func(2, 6) = deriv('z', 27, 1, 1, 1);
		// vertex 7
		func(0, 7) = deriv('x', 30, -1, 1, 1);
		func(1, 7) = deriv('y', 30, -1, 1, 1);
		func(2, 7) = deriv('z', 30, -1, 1, 1);
		// vertex 8
		func(0, 8) = deriv('x', 13, -1, -1, -0.5);
		func(1, 8) = deriv('y', 13, -1, -1, -0.5);
		func(2, 8) = deriv('z', 13, -1, -1, -0.5);
		// vertex 9
		func(0, 9) = deriv('x', 14, 1, -1, -0.5);
		func(1, 9) = deriv('y', 14, 1, -1, -0.5);
		func(2, 9) = deriv('z', 14, 1, -1, -0.5);
		// vertex 10
		func(0, 10) = deriv('x', 15, 1, 1, -0.5);
		func(1, 10) = deriv('y', 15, 1, 1, -0.5);
		func(2, 10) = deriv('z', 15, 1, 1, -0.5);
		// vertex 11
		func(0, 11) = deriv('x', 16, -1, 1, -0.5);
		func(1, 11) = deriv('y', 16, -1, 1, -0.5);
		func(2, 11) = deriv('z', 16, -1, 1, -0.5);
		// vertex 12
		func(0, 12) = deriv('x', 17, -1, -1, 0.5);
		func(1, 12) = deriv('y', 17, -1, -1, 0.5);
		func(2, 12) = deriv('z', 17, -1, -1, 0.5);
		// vertex 13
		func(0, 13) = deriv('x', 18, 1, -1, 0.5);
		func(1, 13) = deriv('y', 18, 1, -1, 0.5);
		func(2, 13) = deriv('z', 18, 1, -1, 0.5);
		// vertex 14
		func(0, 14) = deriv('x', 19, 1, 1, 0.5);
		func(1, 14) = deriv('y', 19, 1, 1, 0.5);
		func(2, 14) = deriv('z', 19, 1, 1, 0.5);
		// vertex 15
		func(0, 15) = deriv('x', 20, -1, 1, 0.5);
		func(1, 15) = deriv('y', 20, -1, 1, 0.5);
		func(2, 15) = deriv('z', 20, -1, 1, 0.5);
		// vertex 16
		func(0, 16) = deriv('x', 2, -0.5, -1, -1);
		func(1, 16) = deriv('y', 2, -0.5, -1, -1);
		func(2, 16) = deriv('z', 2, -0.5, -1, -1);
		// vertex 17
		func(0, 17) = deriv('x', 3, 0.5, -1, -1);
		func(1, 17) = deriv('y', 3, 0.5, -1, -1);
		func(2, 17) = deriv('z', 3, 0.5, -1, -1);
		// vertex 18
		func(0, 18) = deriv('x', 5, 1, -0.5, -1);
		func(1, 18) = deriv('y', 5, 1, -0.5, -1);
		func(2, 18) = deriv('z', 5, 1, -0.5, -1);
		// vertex 19
		func(0, 19) = deriv('x', 6, 1, 0.5, -1);
		func(1, 19) = deriv('y', 6, 1, 0.5, -1);
		func(2, 19) = deriv('z', 6, 1, 0.5, -1);
		// vertex 20
		func(0, 20) = deriv('x', 8, 0.5, 1, -1);
		func(1, 20) = deriv('y', 8, 0.5, 1, -1);
		func(2, 20) = deriv('z', 8, 0.5, 1, -1);
		// vertex 21
		func(0, 21) = deriv('x', 9, -0.5, 1, -1);
		func(1, 21) = deriv('y', 9, -0.5, 1, -1);
		func(2, 21) = deriv('z', 9, -0.5, 1, -1);
		// vertex 22
		func(0, 22) = deriv('x', 11, -1, 0.5, -1);
		func(1, 22) = deriv('y', 11, -1, 0.5, -1);
		func(2, 22) = deriv('z', 11, -1, 0.5, -1);
		// vertex 23
		func(0, 23) = deriv('x', 12, -1, -0.5, -1);
		func(1, 23) = deriv('y', 12, -1, -0.5, -1);
		func(2, 23) = deriv('z', 12, -1, -0.5, -1);
		// vertex 24
		func(0, 24) = deriv('x', 22, -0.5, -1, 1);
		func(1, 24) = deriv('y', 22, -0.5, -1, 1);
		func(2, 24) = deriv('z', 22, -0.5, -1, 1);
		// vertex 25
		func(0, 25) = deriv('x', 23, 0.5, -1, 1);
		func(1, 25) = deriv('y', 23, 0.5, -1, 1);
		func(2, 25) = deriv('z', 23, 0.5, -1, 1);
		// vertex 26
		func(0, 26) = deriv('x', 25, 1, -0.5, 1);
		func(1, 26) = deriv('y', 25, 1, -0.5, 1);
		func(2, 26) = deriv('z', 25, 1, -0.5, 1);
		// vertex 27
		func(0, 27) = deriv('x', 26, 1, 0.5, 1);
		func(1, 27) = deriv('y', 26, 1, 0.5, 1);
		func(2, 27) = deriv('z', 26, 1, 0.5, 1);
		// vertex 28
		func(0, 28) = deriv('x', 28, 0.5, 1, 1);
		func(1, 28) = deriv('y', 28, 0.5, 1, 1);
		func(2, 28) = deriv('z', 28, 0.5, 1, 1);
		// vertex 29
		func(0, 29) = deriv('x', 29, -0.5, 1, 1);
		func(1, 29) = deriv('y', 29, -0.5, 1, 1);
		func(2, 29) = deriv('z', 29, -0.5, 1, 1);
		// vertex 30
		func(0, 30) = deriv('x', 31, -1, 0.5, 1);
		func(1, 30) = deriv('y', 31, -1, 0.5, 1);
		func(2, 30) = deriv('z', 31, -1, 0.5, 1);
		// vertex 31
		func(0, 31) = deriv('x', 32, -1, -0.5, 1);
		func(1, 31) = deriv('y', 32, -1, -0.5, 1);
		func(2, 31) = deriv('z', 32, -1, -0.5, 1);
		break;
	}
	default:
		throw std::invalid_argument("Invalid number of element vertices. Error in file " __FILE__);
	}

	return func;
}


#endif // !HEXAHEDRON_SHAPE_FUNCTIONS_DERIVATIVES_H