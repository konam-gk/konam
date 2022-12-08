#ifndef HEXAHEDRON_SHAPE_FUNCTIONS_H
#define HEXAHEDRON_SHAPE_FUNCTIONS_H


#include <stdexcept>

#include "konam_array.h"


template<typename Type>
void hexahedron_shape_functions(konam_vec& func, Type& type, const konam_mat& abscissa, const int i)
{
	// natural coordinates
	auto xi = abscissa(i, 0);
	auto eta = abscissa(i, 1);
	auto zeta = abscissa(i, 2);


	switch (type) {
	case Type::Hexahedron8:
		func(0) = 0.125 * (1.0 - xi) * (1.0 - eta) * (1.0 - zeta);
		func(1) = 0.125 * (1.0 + xi) * (1.0 - eta) * (1.0 - zeta);
		func(2) = 0.125 * (1.0 + xi) * (1.0 + eta) * (1.0 - zeta);
		func(3) = 0.125 * (1.0 - xi) * (1.0 + eta) * (1.0 - zeta);
		func(4) = 0.125 * (1.0 - xi) * (1.0 - eta) * (1.0 + zeta);
		func(5) = 0.125 * (1.0 + xi) * (1.0 - eta) * (1.0 + zeta);
		func(6) = 0.125 * (1.0 + xi) * (1.0 + eta) * (1.0 + zeta);
		func(7) = 0.125 * (1.0 - xi) * (1.0 + eta) * (1.0 + zeta);
		break;
	case Type::Hexahedron20:	// preveri
	{
		auto shape_fun = [&xi, &eta, &zeta](int vertex, double i, double j, double k) {
			double shape{};
			auto xi2 = xi * xi;
			auto eta2 = eta * eta;
			auto zeta2 = zeta * zeta;

			switch (vertex) {
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				shape = 0.125 * (1.0 + i * xi) * (1.0 + j * eta) * (1.0 + k * zeta)
					* (i * xi + j * eta + k * zeta - 2.0);
				break;
			case 13: case 15: case 17: case 19:
				shape = 0.25 * (1.0 - xi2) * (1.0 + j * eta) * (1.0 + k * zeta);
				break;
			case 14: case 16: case 18: case 20:
				shape = 0.25 * (1.0 - eta2) * (1.0 + k * zeta) * (1.0 + i * xi);
				break;
			case 9: case 10: case 11: case 12:
				shape = 0.25 * (1.0 - zeta2) * (1.0 + j * eta) * (1.0 + i * xi);
				break;
			default:
				throw std::out_of_range("Error in file " __FILE__);
			}
			return shape;
		};

		func(0) = shape_fun(1, -1, -1, -1);
		func(1) = shape_fun(3, 1, -1, -1);
		func(2) = shape_fun(5, 1, 1, -1);
		func(3) = shape_fun(7, -1, 1, -1);
		func(4) = shape_fun(13, -1, -1, 1);		// opomba! i nima vpliva
		func(5) = shape_fun(15, 1, -1, 1);
		func(6) = shape_fun(17, 1, 1, 1);
		func(7) = shape_fun(19, -1, 1, 1);
		func(8) = shape_fun(9, -1, -1, 0);
		func(9) = shape_fun(10, 1, -1, 0);
		func(10) = shape_fun(11, 1, 1, 0);
		func(11) = shape_fun(12, -1, 1, 0);
		func(12) = shape_fun(2, 0, -1, -1);
		func(13) = shape_fun(4, 1, 0, -1);
		func(14) = shape_fun(6, 0, 1, -1);
		func(15) = shape_fun(8, -1, 0, -1);
		func(16) = shape_fun(14, 0, -1, 1);
		func(17) = shape_fun(16, 1, 0, 1);
		func(18) = shape_fun(18, 0, 1, 1);
		func(19) = shape_fun(20, -1, 0, 1);
		break;
	}
	case Type::Hexahedron27:	// preveri
	{
		auto shape_fun = [&xi, &eta, &zeta](int vertex, double i, double j, double k) {
			double shape{};
			auto xi2 = xi * xi;
			auto eta2 = eta * eta;
			auto zeta2 = zeta * zeta;

			switch (vertex) {
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				shape = 0.125 * (xi2 + xi * i) * (eta2 + eta * j) * (zeta2 + zeta * k);
				break;
			case 13: case 14: case 15: case 16: case 9: case 10: case 11: case 12:
			case 17: case 18: case 19: case 20:
				shape = 0.25 * j * j * (eta2 - eta * j) * zeta2 * (zeta2 - zeta * k)
					* (1.0 - zeta2) + 0.25 * k * k * (zeta2 - zeta * k) + i * i * (xi2 - xi * i)
					* (1.0 - eta2) + 0.25 * i * i * (xi2 - xi * i) * j * j * (eta2 - eta * j)
					* (1.0 - zeta2);
				break;
			case 25: case 21: case 22: case 23: case 24: case 26:
				shape = 0.5 * (1.0 - xi2) * (1.0 - eta2) * (zeta + k * zeta2)
					+ 0.5 * (1.0 - eta2) * (1.0 - zeta2) * (xi + i * xi2)
					+ 0.5 * (1.0 - xi2) * (1.0 - zeta2) * (eta + j * eta2);
				break;
			case 27:
				shape = (1.0 - xi2) * (1.0 - eta2) * (1.0 - zeta2);
				break;
			default:
				throw std::out_of_range("Error in file " __FILE__);
			}
			return shape;
		};

		func(0) = shape_fun(1, -1, -1, -1);
		func(1) = shape_fun(3, 1, -1, -1);
		func(2) = shape_fun(5, 1, 1, -1);
		func(3) = shape_fun(7, -1, 1, -1);
		func(4) = shape_fun(19, -1, -1, 1);
		func(5) = shape_fun(21, 1, -1, 1);
		func(6) = shape_fun(23, 1, 1, 1);
		func(7) = shape_fun(25, -1, 1, 1);
		func(8) = shape_fun(10, -1, -1, 0);
		func(9) = shape_fun(12, 1, -1, 0);
		func(10) = shape_fun(14, 1, 1, 0);
		func(11) = shape_fun(16, -1, 1, 0);
		func(12) = shape_fun(2, 0, -1, -1);
		func(13) = shape_fun(4, 1, 0, -1);
		func(14) = shape_fun(6, 0, 1, -1);
		func(15) = shape_fun(8, -1, 0, -1);
		func(16) = shape_fun(20, 0, -1, 1);
		func(17) = shape_fun(22, 1, 0, 1);
		func(18) = shape_fun(24, 0, 1, 1);
		func(19) = shape_fun(26, -1, 0, 1);
		func(20) = shape_fun(11, 0, -1, 0);
		func(21) = shape_fun(13, 1, 0, 0);
		func(22) = shape_fun(15, 0, 1, 0);
		func(23) = shape_fun(17, -1, 0, 0);
		func(24) = shape_fun(9, 0, 0, -1);
		func(25) = shape_fun(27, 0, 0, 1);
		func(26) = shape_fun(18, 0, 0, 0);
		break;
	}
	case Type::Hexahedron32:	// preveri
	{
		auto shape_fun = [&xi, &eta, &zeta](int vertex, double i, double j, double k) {
			double shape{};
			auto xi2 = xi * xi;
			auto eta2 = eta * eta;
			auto zeta2 = zeta * zeta;

			switch (vertex) {
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
				shape = (9.0 / 64.0) * (1.0 + xi * i) * (1.0 + eta * j) * (1.0 + zeta * k)
					* (-19.0 / 9.0 + xi2 + eta2 + zeta2);
			case 17: case 18: case 21: case 22: case 25: case 26: case 29: case 30:
				shape = (81.0 / 64.0) * (1.0 - xi2) * (1.0 / 9.0 + xi * i)
					* (1.0 + eta * j) * (1.0 + zeta * k);
			case 19: case 20: case 23: case 24: case 27: case 28: case 31: case 32:
				shape = (81.0 / 64.0) * (1.0 + xi * i) * (1.0 - eta2)
					* (1.0 / 9.0 + eta * j) * (1.0 + zeta * k);
			case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
				shape = (81.0 / 64.0) * (1.0 + xi * i) * (1.0 + eta * j)
					* (1.0 / 9.0 + zeta * k) * (1.0 - zeta2);
			default:
				throw std::out_of_range("Error in file " __FILE__);
			}
			return shape;
		};

		func(0) = shape_fun(1, -1, -1, -1);
		func(1) = shape_fun(4, 1, -1, -1);
		func(2) = shape_fun(7, 1, 1, -1);
		func(3) = shape_fun(10, -1, 1, -1);
		func(4) = shape_fun(21, -1, -1, 1);
		func(5) = shape_fun(24, 1, -1, 1);
		func(6) = shape_fun(27, 1, 1, 1);
		func(7) = shape_fun(30, -1, 1, 1);
		func(8) = shape_fun(13, -1, -1, -0.5);
		func(9) = shape_fun(14, 1, -1, -0.5);
		func(10) = shape_fun(15, 1, 1, -0.5);
		func(11) = shape_fun(16, -1, 1, -0.5);
		func(12) = shape_fun(17, -1, -1, 0.5);
		func(13) = shape_fun(18, 1, -1, 0.5);
		func(14) = shape_fun(19, 1, 1, 0.5);
		func(15) = shape_fun(20, -1, 1, 0.5);
		func(16) = shape_fun(2, -0.5, -1, -1);
		func(17) = shape_fun(3, 0.5, -1, -1);
		func(18) = shape_fun(5, 1, -0.5, -1);
		func(19) = shape_fun(6, 1, 0.5, -1);
		func(20) = shape_fun(8, 0.5, 1, -1);
		func(21) = shape_fun(9, -0.5, 1, -1);
		func(22) = shape_fun(11, -1, 0.5, -1);
		func(23) = shape_fun(12, -1, -0.5, -1);
		func(24) = shape_fun(22, -0.5, -1, 1);
		func(25) = shape_fun(23, 0.5, -1, 1);
		func(26) = shape_fun(25, 1, -0.5, 1);
		func(27) = shape_fun(26, 1, 0.5, 1);
		func(28) = shape_fun(28, 0.5, 1, 1);
		func(29) = shape_fun(29, -0.5, 1, 1);
		func(30) = shape_fun(31, -1, 0.5, 1);
		func(31) = shape_fun(32, -1, -0.5, 1);
	}
	}

}


#endif // !HEXAHEDRON_SHAPE_FUNCTIONS_H