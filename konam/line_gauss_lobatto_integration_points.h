// The coordinates and related weights for one dimensional integration
// using Lobatto quadrature

#ifndef LINE_GAUSS_LOBATTO_INTEGRATION_POINTS_H
#define LINE_GAUSS_LOBATTO_INTEGRATION_POINTS_H

#include <cmath>
#include <stdexcept>

#include "konam_array.h"

//using namespace boost::numeric::ublas;


auto line_gauss_lobatto_integration_points(const int num_int_pts)
{
	// num_int_pts - number of integration points
	const int dim{ 1 };
	konam_mat coordinates(num_int_pts, dim);
	konam_vec weights(num_int_pts);

	switch (num_int_pts) {
	case 2:
		coordinates(0) = -1.0;						weights(0) = 1.0;
		coordinates(1) = +1.0;						weights(1) = 1.0;
		break;
	case 3:
		coordinates(0) = -1.0;						weights(0) = 1.0 / 3.0;
		coordinates(1) = 0.0;						weights(1) = 4.0 / 3.0;
		coordinates(2) = +1.0;						weights(2) = 1.0 / 3.0;
		break;
	case 4:
		coordinates(0) = -1.0;						weights(0) = 1.0 / 6.0;
		coordinates(1) = -std::sqrt(1.0 / 5.0);		weights(1) = 5.0 / 6.0;
		coordinates(2) = +std::sqrt(1.0 / 5.0);		weights(2) = 5.0 / 6.0;
		coordinates(3) = +1.0;						weights(3) = 1.0 / 6.0;
		break;
	case 5:
		coordinates(0) = -1.0;						weights(0) = 1.0 / 10.0;
		coordinates(1) = -std::sqrt(3.0 / 7.0);		weights(1) = 49.0 / 90.0;
		coordinates(2) = 0.0;						weights(2) = 32.0 / 45.0;
		coordinates(3) = +std::sqrt(3.0 / 7.0);		weights(3) = 49.0 / 90.0;
		coordinates(4) = +1.0;						weights(4) = 1.0 / 10.0;
		break;
	case 6:
		coordinates(0) = -1.0;						weights(0) = 1.0 / 15.0;
		coordinates(1) = -0.285231516480645;		weights(1) = 0.554858377035486;
		coordinates(2) = -0.765055323929465;		weights(2) = 0.378474956297847;
		coordinates(3) = +0.765055323929465;		weights(3) = 0.378474956297847;
		coordinates(4) = +0.285231516480645;		weights(4) = 0.554858377035486;
		coordinates(5) = +1.0;						weights(5) = 1.0 / 15.0;
		break;
	default:
		throw std::out_of_range("Invalid number of integration points. Error in file " __FILE__);
	}
	return std::make_pair(coordinates, weights);
}

#endif // !LINE_GAUSS_LOBATTO_INTEGRATION_POINTS_H
