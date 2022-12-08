#ifndef LINE_SHAPE_FUNCTIONS_DERIVATIVES_H
#define LINE_SHAPE_FUNCTIONS_DERIVATIVES_H


#include <stdexcept>

#include "konam_array.h"


template<unsigned int NVT>
// NVT - number of element vertices
auto line_shape_functions_derivatives(const konam_mat& abscissa, const int i)
{
	konam_mat func(1, NVT);

	// natural coordinate
	auto xi = abscissa(i);

	// help variable
	auto xi2 = xi * xi;
	auto xi3 = xi * xi * xi;


	switch (NVT) {
	case 2:
		// vertex 0
		func(0, 0) = -0.5;
		// vertex 1
		func(0, 1) = 0.5;
		break;
	case 3:
		// vertex 0
		func(0, 0) = xi - 0.5;
		// vertex 1
		func(0, 1) = xi + 0.5;
		// vertex 2
		func(0, 2) = -2.0 * xi;
		break;
	case 4:
		// vertex 0
		func(0, 0) = -(1.0 / 16.0) * (27.0 * xi2 - 18.0 * xi - 1.0);
		// vertex 1
		func(0, 1) = (1.0 / 16.0) * (18.0 * xi2 + 18.0 * xi - 1.0);
		// vertex 2
		func(0, 2) = (9.0 / 16.0) * (9.0 * xi2 - 2.0 * xi - 3.0);
		// vertex 3
		func(0, 3) = -(9.0 / 16.0) * (xi2 + 2.0 * xi - 3.0);
		break;
	case 5:
		func(0, 0) = (1.0 / 6.0) * (16.0 * xi3 - 12.0 * xi2 - 2.0 * xi + 1.0);
		func(0, 1) = -(8.0 / 3.0) * (4.0 * xi3 - 1.5 * xi2 - 2.0 * xi + 0.5);
		func(0, 2) = 4.0 * (4.0 * xi3 - 3.0 * xi2 - 0.5 * xi + 0.25);
		func(0, 3) = -(8.0 / 3.0) * (4.0 * xi3 + 1.5 * xi2 - 2.0 * xi - 0.5);
		func(0, 4) = (1.0 / 6.0) * (16.0 * xi3 + 12.0 * xi2 - 2.0 * xi - 1.0);
		break;
	default:
		throw std::invalid_argument("Invalid number of element vertices. Error in file " __FILE__);
	}

	return func;
}


#endif // !LINE_SHAPE_FUNCTIONS_DERIVATIVES_H