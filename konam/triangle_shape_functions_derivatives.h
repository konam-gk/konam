#ifndef TRIANGLE_SHAPE_FUNCTIONS_DERIVATIVES_H
#define TRIANGLE_SHAPE_FUNCTIONS_DERIVATIVES_H


#include <stdexcept>

#include "konam_array.h"


template<unsigned int NVT>
// NVT - number of element vertices
auto triangle_shape_functions_derivatives(const konam_mat& abscissa, const int i)
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
	case 3:
		// vertex 0
		func(0, 0) = -1.0;
		func(1, 0) = -1.0;
		// vertex 1
		func(0, 1) = 1.0;
		func(1, 1) = 0.0;
		// vertex 2
		func(0, 2) = 0.0;
		func(1, 2) = 1.0;
		break;
	case 6:
		// vertex 0
		func(0, 0) = 4.0 * xi + 4.0 * eta - 3.0;
		func(1, 0) = 4.0 * xi + 4.0 * eta - 3.0;
		// vertex 1
		func(0, 1) = 4.0 * xi - 1.0;
		func(1, 1) = 0.0;
		// vertex 2
		func(0, 2) = 0.0;
		func(1, 2) = 4.0 * eta - 1.0;
		// vertex 3
		func(0, 3) = 4.0 * (-2.0 * xi - eta + 1.0);
		func(1, 3) = -4.0 * xi;
		// vertex 4
		func(0, 4) = 4.0 * eta;
		func(1, 4) = 4.0 * xi;
		// vertex 5
		func(0, 5) = -4.0 * eta;
		func(1, 5) = 4.0 * (-2.0 * eta - xi + 1.0);
		break;
	case 10:
		// vertex 0
		func(0, 0) = 0.5 * (-27.0 * xi2 + 36.0 * xi - 54.0 * xi * eta + 36.0 * eta - 27.0 * eta2 - 11.0);
		func(1, 0) = 0.5 * (-27.0 * xi2 + 36.0 * xi - 54.0 * xi * eta + 36.0 * eta - 27.0 * eta2 - 11.0);
		// vertex 1
		func(0, 1) = 0.5 * (27.0 * xi2 - 18.0 * xi + 2.0);
		func(1, 1) = 0.0;
		// vertex 2
		func(0, 2) = 0.0;
		func(1, 2) = 0.5 * (27.0 * eta2 - 18.0 * eta + 2.0);
		// vertex 3
		func(0, 3) = 4.5 * (9.0 * xi2 + 12.0 * xi * eta - 10.0 * xi + 3.0 * eta2 - 5.0 * eta + 2.0);
		func(1, 3) = 4.5 * xi * (6.0 * xi + 6.0 * eta - 5.0);
		// vertex 4
		func(0, 4) = 4.5 * (-9.0 * xi2 - 6.0 * xi * eta + 8.0 * xi + eta - 1.0);
		func(1, 4) = -4.5 * xi * (3.0 * xi - 1.0);
		// vertex 5
		func(0, 5) = 4.5 * eta * (6.0 * xi - 1.0);
		func(1, 5) = 4.5 * xi * (3.0 * xi - 1.0);
		// vertex 6
		func(0, 6) = 4.5 * eta * (3.0 * eta - 1.0);
		func(1, 6) = 4.5 * xi * (6.0 * eta - 1.0);
		// vertex 7
		func(0, 7) = -4.5 * eta * (3.0 * eta - 1.0);
		func(1, 7) = 4.5 * (-9.0 * eta2 - 6.0 * eta * xi + 8.0 * eta + xi - 1.0);
		// vertex 8
		func(0, 8) = 4.5 * eta * (6.0 * xi + 6.0 * eta - 5.0);
		func(1, 8) = 4.5 * (9.0 * eta2 + 12.0 * xi * eta - 10.0 * eta + 3.0 * xi2 - 5.0 * xi + 2.0);
		// vertex 9
		func(0, 9) = 27.0 * eta * (-2.0 * xi - eta + 1.0);
		func(1, 9) = 27.0 * xi * (-2.0 * eta - xi + 1.0);
		break;
	case 15:
		// vertex 0
		func(0, 0) = (1.0 / 3.0) * (128.0 * xi3 + 384.0 * xi2 * eta - 240.0 * xi2 + 384.0 * xi * eta2 + 140.0 * xi
			- 480.0 * xi * eta + 128.0 * eta3 + 140.0 * eta - 240.0 * eta2 - 25.0);
		func(1, 0) = (1.0 / 3.0) * (128.0 * xi3 + 384.0 * xi2 * eta - 240.0 * xi2 + 384.0 * xi * eta2 + 140.0 * xi
			- 480.0 * xi * eta + 128.0 * eta3 + 140.0 * eta - 240.0 * eta2 - 25.0);
		// vertex 1
		func(0, 1) = (1.0 / 3.0) * (128.0 * xi3 - 144.0 * xi2 + 44.0 * xi - 3.0);
		func(1, 1) = 0.0;
		// vertex 2
		func(0, 2) = 0.0;
		func(1, 2) = (1.0 / 3.0) * (128.0 * eta3 - 144.0 * eta2 + 44.0 * eta - 3.0);
		// vertex 3
		func(0, 3) = (8.0 / 3.0) * (-64.0 * xi3 - 144.0 * xi2 * eta + 108.0 * xi2 - 96.0 * xi * eta2 + 144.0 * xi * eta - 52.0 * xi
			- 16.0 * eta3 + 36.0 * eta2 - 26.0 * eta + 6.0);
		func(1, 3) = (8.0 / 3.0) * xi * (-48.0 * xi2 + 72.0 * xi - 96.0 * xi * eta + 72.0 * eta - 48.0 * eta2 - 26.0);
		// vertex 4
		func(0, 4) = 256.0 * xi3 + 384.0 * xi2 * eta - 384.0 * xi2 + 128.0 * xi * eta2 - 288.0 * xi * eta + 152.0 * xi - 16.0 * eta2 + 28.0 * eta - 12.0;
		func(1, 4) = xi * (8.0 * xi - 2.0) * (16.0 * xi + 16.0 * eta - 14.0);
		// vertex 5
		func(0, 5) = (8.0 / 3.0) * (-64.0 * xi3 - 48.0 * xi2 * eta + 84.0 * xi2 + 24.0 * xi * eta - 28.0 * xi - 2.0 * eta + 2.0);
		func(1, 5) = -(8.0 / 3.0) * xi * (4.0 * xi - 1.0) * (4.0 * xi - 2.0);
		// vertex 6
		func(0, 6) = (8.0 / 3.0) * eta * (48.0 * xi2 - 24.0 * xi + 2.0);
		func(1, 6) = (8.0 / 3.0) * xi * (4.0 * xi - 1.0) * (4.0 * xi - 2.0);
		// vertex 7
		func(0, 7) = eta * (8.0 * eta - 2.0) * (16.0 * xi - 2.0);
		func(1, 7) = xi * (8.0 * xi - 2.0) * (16.0 * eta - 2.0);
		// vertex 8
		func(0, 8) = (8.0 / 3.0) * eta * (4.0 * eta - 1.0) * (4.0 * eta - 2.0);
		func(1, 8) = (8.0 / 3.0) * xi * (48.0 * eta2 - 24.0 * eta + 2.0);
		// vertex 9
		func(0, 9) = -(8.0 / 3.0) * eta * (4.0 * eta - 1.0) * (4.0 * eta - 2.0);
		func(1, 9) = (8.0 / 3.0) * (-64.0 * eta3 - 48.0 * xi * eta2 + 84.0 * eta2 + 24.0 * xi * eta - 28.0 * eta - 2.0 * xi + 2.0);
		// vertex 10
		func(0, 10) = eta * (8.0 * eta - 2.0) * (16.0 * xi + 16.0 * eta - 14.0);
		func(1, 10) = 256.0 * eta3 + 384.0 * xi * eta2 - 384.0 * eta2 + 128.0 * xi2 * eta - 288.0 * xi * eta
			+ 152.0 * eta - 16.0 * xi2 + 28.0 * xi - 12.0;
		// vertex 11
		func(0, 11) = (8.0 / 3.0) * eta * (-48.0 * xi2 + 72.0 * xi - 96.0 * xi * eta + 72.0 * eta - 48.0 * eta2 - 26.0);
		func(1, 11) = (8.0 / 3.0) * (-64.0 * eta3 - 144.0 * xi * eta2 + 108.0 * eta2 - 96.0 * xi2 * eta + 144.0 * xi * eta
			- 52.0 * eta - 16.0 * xi3 + 36.0 * xi2 - 26.0 * xi + 6.0);
		// vertex 12
		func(0, 12) = 16.0 * eta * (24.0 * xi2 + 32.0 * xi * eta - 28.0 * xi + 8.0 * eta2 - 14.0 * eta + 6.0);
		func(1, 12) = 16.0 * xi * (24.0 * eta2 + 32.0 * xi * eta - 28.0 * eta + 8.0 * xi2 - 14.0 * xi + 6.0);
		// vertex 13
		func(0, 13) = 16.0 * eta * (-24.0 * xi2 - 16.0 * xi * eta + 20.0 * xi + 2.0 * eta - 2.0);
		func(1, 13) = 16.0 * xi * (8.0 * xi - 2.0) * (-2.0 * eta - xi + 1.0);
		// vertex 14
		func(0, 14) = 16.0 * eta * (8.0 * eta - 2.0) * (-2.0 * xi - eta + 1.0);
		func(1, 14) = 16.0 * xi * (-24.0 * eta2 - 16.0 * xi * eta + 20.0 * eta + 2.0 * xi - 2.0);
		break;
	default:
		throw std::invalid_argument("Invalid number of element vertices. Error in file " __FILE__);
	}

	return func;
}


#endif // !TRIANGLE_SHAPE_FUNCTIONS_DERIVATIVES_H