#ifndef QUADRANGLE_SHAPE_FUNCTIONS_DERIVATIVES_H
#define QUADRANGLE_SHAPE_FUNCTIONS_DERIVATIVES_H


#include <stdexcept>

#include "konam_array.h"


template<unsigned int NVT>
// NVT - number of element vertices
auto quadrangle_shape_functions_derivatives(const konam_mat& abscissa, const int i)
{
	konam_mat func(2, NVT);

	// natural coordinates
	auto xi = abscissa(i, 0);
	auto eta = abscissa(i, 1);

	// help variables
	auto xi2 = xi * xi;
	auto eta2 = eta * eta;
	auto xi3 = xi * xi * xi;
	auto eta3 = eta * eta * eta;


	switch (NVT) {
	case 4:
		// vertex 0
		func(0, 0) = 0.25 * (eta - 1.0);
		func(1, 0) = 0.25 * (xi - 1.0);
		// vertex 1
		func(0, 1) = 0.25 * (1.0 - eta);
		func(1, 1) = -0.25 * (1.0 + xi);
		// vertex 2
		func(0, 2) = 0.25 * (1.0 + eta);
		func(1, 2) = 0.25 * (1.0 + xi);
		// vertex 3
		func(0, 3) = -0.25 * (1.0 + eta);
		func(1, 3) = 0.25 * (1.0 - xi);
		break;
	case 8:
		// vertex 0
		func(0, 0) = -0.25 * (1.0 - eta) * (-2.0 * xi - eta);
		func(1, 0) = -0.25 * (1.0 - xi) * (-xi - 2.0 * eta);
		// vertex 1
		func(0, 1) = 0.25 * (1.0 - eta) * (2.0 * xi - eta);
		func(1, 1) = 0.25 * (1.0 + xi) * (2.0 * eta - xi);
		// vertex 2
		func(0, 2) = 0.25 * (1.0 + eta) * (2.0 * xi + eta);
		func(1, 2) = 0.25 * (1.0 + xi) * (xi + 2.0 * eta);
		// vertex 3
		func(0, 3) = -0.25 * (1.0 + eta) * (eta - 2.0 * xi);
		func(1, 3) = -0.25 * (1.0 - xi) * (xi - 2.0 * eta);
		// vertex 4
		func(0, 4) = -xi * (-eta + 1.0);
		func(1, 4) = 0.5 * (-1.0 + xi2);
		// vertex 5
		func(0, 5) = 0.5 * (1.0 - eta2);
		func(1, 5) = -eta * (xi + 1.0);
		// vertex 6
		func(0, 6) = -xi * (eta + 1.0);
		func(1, 6) = 0.5 * (1.0 - xi2);
		// vertex 7
		func(0, 7) = 0.5 * (-1.0 + eta2);
		func(1, 7) = -eta * (-xi + 1.0);
		break;
	case 9:
		// vertex 0
		func(0, 0) = 0.25 * (eta2 - eta) * (2.0 * xi - 1.0);
		func(1, 0) = 0.25 * (xi2 - xi) * (2.0 * eta - 1.0);
		// vertex 1
		func(0, 1) = 0.25 * (eta2 - eta) * (2.0 * xi + 1.0);
		func(1, 1) = 0.25 * (xi2 + xi) * (2.0 * eta - 1.0);
		// vertex 2
		func(0, 2) = 0.25 * (eta2 + eta) * (2.0 * xi + 1.0);
		func(1, 2) = 0.25 * (xi2 + xi) * (2.0 * eta + 1.0);
		// vertex 3
		func(0, 3) = 0.25 * (eta2 + eta) * (2.0 * xi - 1.0);
		func(1, 3) = 0.25 * (xi2 - xi) * (2.0 * eta + 1.0);
		// vertex 4
		func(0, 4) = -xi * (eta2 - eta);
		func(1, 4) = 0.5 * (1.0 - xi2) * (2.0 * eta - 1.0);
		// vertex 5
		func(0, 5) = 0.5 * (1.0 - eta2) * (2.0 * xi + 1.0);
		func(1, 5) = -eta * (xi2 + xi);
		// vertex 6
		func(0, 6) = -xi * (eta2 + eta);
		func(1, 6) = 0.5 * (1.0 - xi2) * (2.0 * eta + 1.0);
		// vertex 7
		func(0, 7) = 0.5 * (1.0 - eta2) * (2.0 * xi - 1.0);
		func(1, 7) = -eta * (xi2 - xi);
		// vertex 8
		func(0, 8) = -2.0 * xi * (1.0 - eta2);
		func(1, 8) = -2.0 * eta * (1.0 - xi2);
		break;
	case 12:
		// vertex 0
		func(0, 0) = (1.0 / 32.0) * (1.0 - eta) * (-27.0 * xi2 + 18.0 * xi - 9.0 * eta2 + 10.0);
		func(1, 0) = (1.0 / 32.0) * (1.0 - xi) * (-27.0 * eta2 + 18.0 * eta - 9.0 * xi2 + 10.0);
		// vertex 1
		func(0, 1) = (1.0 / 32.0) * (1.0 - eta) * (27.0 * xi2 + 18.0 * xi + 9.0 * eta2 - 10.0);
		func(1, 1) = (1.0 / 32.0) * (1.0 + xi) * (-27.0 * eta2 + 18.0 * eta - 9.0 * xi2 + 10.0);
		// vertex 2
		func(0, 2) = (1.0 / 32.0) * (1.0 + eta) * (27.0 * xi2 + 18.0 * xi + 9.0 * eta2 - 10.0);
		func(1, 2) = (1.0 / 32.0) * (1.0 + xi) * (27.0 * eta2 + 18.0 * eta + 9.0 * xi2 - 10.0);
		// vertex 3
		func(0, 3) = (1.0 / 32.0) * (1.0 + eta) * (-27.0 * xi2 + 18.0 * xi - 9.0 * eta2 + 10.0);
		func(1, 3) = (1.0 / 32.0) * (1.0 - xi) * (27.0 * eta2 + 18.0 * eta + 9.0 * xi2 - 10.0);
		// vertex 4
		func(0, 4) = (1.0 / 32.0) * 9.0 * (1.0 - eta) * (9.0 * xi2 - 2.0 * xi - 3.0);
		func(1, 4) = (1.0 / 32.0) * (-9.0 + 27.0 * xi + 9.0 * xi2 - 27.0 * xi3);
		// vertex 5
		func(0, 5) = (1.0 / 32.0) * 9.0 * (1.0 - eta) * (-9.0 * xi2 - 2.0 * xi + 3.0);
		func(1, 5) = (1.0 / 32.0) * (-9.0 - 27.0 * xi + 9.0 * xi2 + 27.0 * xi3);
		// vertex 6
		func(0, 6) = (1.0 / 32.0) * (9.0 - 27.0 * eta - 9.0 * eta2 + 27.0 * eta3);
		func(1, 6) = (1.0 / 32.0) * 9.0 * (1.0 + xi) * (9.0 * eta2 - 2.0 * eta - 3.0);
		// vertex 7
		func(0, 7) = (1.0 / 32.0) * (9.0 + 27.0 * eta - 9.0 * eta2 - 27.0 * eta3);
		func(1, 7) = (1.0 / 32.0) * 9.0 * (1.0 + xi) * (-9.0 * eta2 - 2.0 * eta + 3.0);
		// vertex 8
		func(0, 8) = (1.0 / 32.0) * 9.0 * (1.0 + eta) * (-9.0 * xi2 - 2.0 * xi + 3.0);
		func(1, 8) = (1.0 / 32.0) * (9.0 + 27.0 * xi - 9.0 * xi2 - 27.0 * xi3);
		// vertex 9
		func(0, 9) = (1.0 / 32.0) * 9.0 * (1.0 + eta) * (9.0 * xi2 - 2.0 * xi - 3.0);
		func(1, 9) = (1.0 / 32.0) * (9.0 - 27.0 * xi - 9.0 * xi2 + 27.0 * xi3);
		// vertex 10
		func(0, 10) = (1.0 / 32.0) * (-9.0 - 27.0 * eta + 9.0 * eta2 + 27.0 * eta3);
		func(1, 10) = (1.0 / 32.0) * 9.0 * (1.0 - xi) * (-9.0 * eta2 - 2.0 * eta + 3.0);
		// vertex 11
		func(0, 11) = (1.0 / 32.0) * (-9.0 + 27.0 * eta + 9.0 * eta2 - 27.0 * eta3);
		func(1, 11) = (1.0 / 32.0) * 9.0 * (1.0 - xi) * (9.0 * eta2 - 2.0 * eta - 3.0);
		break;
	case 16:
		// vertex 0
		func(0, 0) = (1.0 / 256.0) * (243.0 * xi2 * eta3 - 162.0 * xi * eta3 - 9.0 * eta3 - 243.0 * xi2 * eta2 + 162.0 * xi * eta2 + 9.0 * eta2 - 27.0 * xi2 * eta + 18.0 * xi * eta + eta - 1.0 + 27.0 * xi2 - 18.0 * xi);
		func(1, 0) = (1.0 / 256.0) * (243.0 * xi3 * eta2 - 162.0 * xi3 * eta - 9.0 * xi3 - 243.0 * xi2 * eta2 + 162.0 * xi2 * eta + 9.0 * xi2 - 27.0 * xi * eta2 + 18.0 * xi * eta + xi - 1.0 + 27.0 * eta2 - 18.0 * eta);
		// vertex 1
		func(0, 1) = (1.0 / 256.0) * (-9.0 * eta2 + 1.0) * (-27.0 * xi2 - 18.0 * xi + 1.0) * (-eta + 1.0);
		func(1, 1) = (1.0 / 256.0) * (-243.0 * xi3 * eta2 + 162.0 * xi3 * eta + 9.0 * xi3 - 243.0 * xi2 * eta2 + 162.0 * xi2 * eta + 9.0 * xi2 + 27.0 * xi * eta2 - 18.0 * xi * eta - xi - 1.0 + 27.0 * eta2 - 18.0 * eta);
		// vertex 2
		func(0, 2) = (1.0 / 256.0) * (-9.0 * eta2 + 1.0) * (-27.0 * xi2 - 18.0 * xi + 1.0) * (eta + 1.0);
		func(1, 2) = (1.0 / 256.0) * (-9.0 * xi2 + 1.0) * (-27.0 * eta2 - 18.0 * eta + 1.0) * (xi + 1.0);
		// vertex 3
		func(0, 3) = (1.0 / 256.0) * (-243.0 * xi2 * eta3 + 162.0 * xi * eta3 + 9.0 * eta3 - 243.0 * xi2 * eta2 + 162.0 * xi * eta2 + 9.0 * eta2 + 27.0 * xi2 * eta - 18.0 * xi * eta - eta - 1.0 + 27.0 * xi2 - 18.0 * xi);
		func(1, 3) = (1.0 / 256.0) * (-9.0 * xi2 + 1.0) * (-27.0 * eta2 - 18.0 * eta + 1.0) * (-xi + 1.0);
		// vertex 4
		func(0, 4) = (1.0 / 256.0) * 9.0 * (9.0 * xi2 - 2.0 * xi - 3.0) * (9.0 * eta2 - 1.0) * (-eta + 1.0);
		func(1, 4) = (1.0 / 256.0) * 9.0 * (-27.0 * eta2 + 18.0 * eta + 1.0) * (-3.0 * xi + 1.0) * (-xi2 + 1.0);
		// vertex 5
		func(0, 5) = (1.0 / 256.0) * 9.0 * (-9.0 * xi2 - 2.0 * xi + 3.0) * (9.0 * eta2 - 1.0) * (-eta + 1.0);
		func(1, 5) = (1.0 / 256.0) * 9.0 * (-27.0 * eta2 + 18.0 * eta + 1.0) * (3.0 * xi + 1.0) * (-xi2 + 1.0);
		// vertex 6
		func(0, 6) = (1.0 / 256.0) * 9.0 * (-3.0 * eta + 1.0) * (27.0 * xi2 + 18.0 * xi - 1.0) * (-eta2 + 1.0);
		func(1, 6) = (1.0 / 256.0) * 9.0 * (9.0 * eta2 - 2.0 * eta - 3.0) * (9.0 * xi2 - 1.0) * (xi + 1.0);
		// vertex 7
		func(0, 7) = (1.0 / 256.0) * 9.0 * (3.0 * eta + 1.0) * (27.0 * xi2 + 18.0 * xi - 1.0) * (-eta2 + 1.0);
		func(1, 7) = (1.0 / 256.0) * 9.0 * (-9.0 * eta2 - 2.0 * eta + 3.0) * (9.0 * xi2 - 1.0) * (xi + 1.0);
		// vertex 8
		func(0, 8) = (1.0 / 256.0) * 9.0 * (-9.0 * xi2 - 2.0 * xi + 3.0) * (9.0 * eta2 - 1.0) * (eta + 1.0);
		func(1, 8) = (1.0 / 256.0) * 9.0 * (3.0 * xi + 1.0) * (27.0 * eta2 + 18.0 * eta - 1.0) * (-xi2 + 1.0);
		// vertex 9
		func(0, 9) = (1.0 / 256.0) * 9.0 * (9.0 * xi2 - 2.0 * xi - 3.0) * (9.0 * eta2 - 1.0) * (eta + 1.0);
		func(1, 9) = (1.0 / 256.0) * 9.0 * (-3.0 * xi + 1.0) * (27.0 * eta2 + 18.0 * eta - 1.0) * (-xi2 + 1.0);
		// vertex 10
		func(0, 10) = (1.0 / 256.0) * 9.0 * (-27.0 * xi2 + 18.0 * xi + 1.0) * (3.0 * eta + 1.0) * (-eta2 + 1.0);
		func(1, 10) = (1.0 / 256.0) * 9.0 * (-9.0 * eta2 - 2.0 * eta + 3.0) * (9.0 * xi2 - 1.0) * (-xi + 1.0);
		// vertex 11
		func(0, 11) = (1.0 / 256.0) * 9.0 * (-27.0 * xi2 + 18.0 * xi + 1.0) * (-3.0 * eta + 1.0) * (-eta2 + 1.0);
		func(1, 11) = (1.0 / 256.0) * 9.0 * (9.0 * eta2 - 2.0 * eta - 3.0) * (9.0 * xi2 - 1.0) * (-xi + 1.0);
		// vertex 12
		func(0, 12) = (1.0 / 256.0) * (2187.0 * xi2 * eta3 - 486.0 * xi * eta3 - 729.0 * eta3 - 2187.0 * xi2 * eta + 486.0 * xi * eta + 729.0 * eta - 729.0 * xi2 * eta2 + 162.0 * xi * eta2 - 162.0 * xi + 243.0 * eta2 + 729.0 * xi2 - 243.0);
		func(1, 12) = (1.0 / 256.0) * (2187.0 * xi3 * eta2 - 486.0 * xi3 * eta - 729.0 * xi3 - 2187.0 * xi * eta2 + 486.0 * xi * eta + 729.0 * xi - 729.0 * xi2 * eta2 + 162.0 * xi2 * eta - 162.0 * eta + 243.0 * xi2 + 729.0 * eta2 - 243.0);
		// vertex 13
		func(0, 13) = (1.0 / 256.0) * (-2187.0 * xi2 * eta3 - 486.0 * xi * eta3 + 729.0 * eta3 + 2187.0 * xi2 * eta + 486.0 * xi * eta - 729.0 * eta + 729.0 * xi2 * eta2 + 162.0 * xi * eta2 - 162.0 * xi - 243.0 * eta2 - 729.0 * xi2 + 243.0);
		func(1, 13) = (1.0 / 256.0) * (-2187.0 * xi3 * eta2 + 486.0 * xi3 * eta + 729.0 * xi3 + 2187.0 * xi * eta2 - 486.0 * xi * eta - 729.0 * xi - 729.0 * xi2 * eta2 + 162.0 * xi2 * eta - 162.0 * eta + 243.0 * xi2 + 729.0 * eta2 - 243.0);
		// vertex 14
		func(0, 14) = (1.0 / 256.0) * (2187.0 * xi2 * eta3 + 486.0 * xi * eta3 - 729.0 * eta3 - 2187.0 * xi2 * eta - 486.0 * xi * eta + 729.0 * eta + 729.0 * xi2 * eta2 + 162.0 * xi * eta2 - 162.0 * xi - 243.0 * eta2 - 729.0 * xi2 + 243.0);
		func(1, 14) = (1.0 / 256.0) * (2187.0 * xi3 * eta2 + 486.0 * xi3 * eta - 729.0 * xi3 - 2187.0 * xi * eta2 - 486.0 * xi * eta + 729.0 * xi + 729.0 * xi2 * eta2 + 162.0 * xi2 * eta - 162.0 * eta - 243.0 * xi2 - 729.0 * eta2 + 243.0);
		// vertex 15
		func(0, 15) = (1.0 / 256.0) * (-2187.0 * xi2 * eta3 + 486.0 * xi * eta3 + 729.0 * eta3 + 2187.0 * xi2 * eta - 486.0 * xi * eta - 729.0 * eta - 729.0 * xi2 * eta2 + 162.0 * xi * eta2 - 162.0 * xi + 243.0 * eta2 + 729.0 * xi2 - 243.0);
		func(1, 15) = (1.0 / 256.0) * (-2187.0 * xi3 * eta2 - 486.0 * xi3 * eta + 729.0 * xi3 + 2187.0 * xi * eta2 + 486.0 * xi * eta - 729.0 * xi + 729.0 * xi2 * eta2 + 162.0 * xi2 * eta - 162.0 * eta - 243.0 * xi2 - 729.0 * eta2 + 243.0);
		break;
	default:
		throw std::invalid_argument("Invalid number of element vertices. Error in file " __FILE__);
	}

	return func;
}


#endif // !QUADRANGLE_SHAPE_FUNCTIONS_DERIVATIVES_H