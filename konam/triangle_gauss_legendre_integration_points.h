// The coordinates and related weights for isoparametric Triangle Domains
// using Gauss-Legendre quadrature

#ifndef TRIANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
#define TRIANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H

#include <stdexcept>

#include "konam_array.h"


auto triangle_gauss_legendre_integration_points(const int num_int_pts)
{
	// num_int_pts - number of integration points
	const int dim{ 2 };
	konam_mat coordinates(num_int_pts, dim);
	konam_vec weights(num_int_pts);

	switch (num_int_pts) {
	case 1:
		// point 1
		coordinates(0, 0) = 1.0 / 3.0;				weights(0) = 1.0 / 2.0;
		coordinates(0, 1) = 1.0 / 3.0;
		break;
	case 3:
		// point 1
		coordinates(0, 0) = 1.0 / 6.0;				weights(0) = 1.0 / 6.0;
		coordinates(0, 1) = 1.0 / 6.0;					
		// point 2
		coordinates(1, 0) = 2.0 / 3.0;				weights(1) = 1.0 / 6.0;
		coordinates(1, 1) = 1.0 / 6.0;
		// point 3
		coordinates(2, 0) = 1.0 / 6.0;				weights(2) = 1.0 / 6.0;
		coordinates(2, 1) = 2.0 / 3.0;
		break;
	case 4:
		// point 1
		coordinates(0, 0) = 1.0 / 6.0;				weights(0) = 25.0 / 96.0;
		coordinates(0, 1) = 1.0 / 6.0;					
		// point 2
		coordinates(1, 0) = 2.0 / 3.0;				weights(1) = 25.0 / 96.0;
		coordinates(1, 1) = 1.0 / 6.0;					
		// point 3
		coordinates(2, 0) = 1.0 / 6.0;				weights(2) = 25.0 / 96.0;
		coordinates(2, 1) = 2.0 / 3.0;
		// point 4
		coordinates(3, 0) = 1.0 / 3.0;				weights(3) = -9.0 / 32.0;
		coordinates(3, 1) = 1.0 / 3.0;
		break;
	case 7:
		// point 1
		coordinates(0, 0) = 0.0;					weights(0) = 1.0 / 40.0;
		coordinates(0, 1) = 0.0;						
		// point 2
		coordinates(1, 0) = 1.0 / 2.0;				weights(1) = 1.0 / 15.0;
		coordinates(1, 1) = 0.0;						
		// point 3
		coordinates(2, 0) = 1.0;					weights(2) = 1.0 / 15.0;
		coordinates(2, 1) = 0.0;						
		// point 4
		coordinates(3, 0) = 1.0 / 2.0;				weights(3) = 1.0 / 15.0;
		coordinates(3, 1) = 1.0 / 2.0;
		// point 5
		coordinates(4, 0) = 0.0;					weights(4) = 1.0 / 40.0;
		coordinates(4, 1) = 1.0;
		// point 6
		coordinates(5, 0) = 0.0;					weights(5) = 1.0 / 40.0;
		coordinates(5, 1) = 1.0 / 2.0;
		// point 7
		coordinates(6, 0) = 1.0 / 3.0;				weights(6) = 9.0 / 40.0;
		coordinates(6, 1) = 1.0 / 3.0;
		break;
	default:
		throw std::invalid_argument("Invalid number of integration points. Error in file " __FILE__);
	}
	return std::make_pair(coordinates, weights);
}

#endif // !TRIANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
