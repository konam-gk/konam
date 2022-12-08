// The coordinates and related weights for one dimensional integration
// using Gauss-Legendre quadrature

#ifndef LINE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
#define LINE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H

#include <cmath>
#include <stdexcept>

#include "konam_array.h"

//sing namespace boost::numeric::ublas;


auto line_gauss_legendre_integration_points(const int num_int_pts)
{
	// num_int_pts - number of integration points
	const int dim{ 1 };
	konam_mat coordinates(num_int_pts, dim);
	konam_vec weights(num_int_pts);

	switch (num_int_pts) {
	case 1:
		coordinates(0) = 0.0;						weights(0) = 2.0;
		break;
	case 2:
		coordinates(0) = -std::sqrt(1.0 / 3.0);		weights(0) = 1.0;
		coordinates(1) = +std::sqrt(1.0 / 3.0);		weights(1) = 1.0;
		break;
	case 3:
		coordinates(0) = -std::sqrt(3.0 / 5.0);		weights(0) = 5.0 / 9.0;
		coordinates(1) = 0.0;						weights(1) = 8.0 / 9.0;
		coordinates(2) = +std::sqrt(3.0 / 5.0);		weights(2) = 5.0 / 9.0;
		break;
	case 4:
		coordinates(0) = -0.861136311594053;		weights(0) = 0.347854845137454;
		coordinates(1) = -0.339981043584856;		weights(1) = 0.652145154862546;
		coordinates(2) = +0.339981043584856;		weights(2) = 0.652145154862546;
		coordinates(3) = +0.861136311594053;		weights(3) = 0.347854845137454;
		break;
	case 5:
		coordinates(0) = -0.906179845938664;		weights(0) = 0.236926885056189;
		coordinates(1) = -0.538469310105683;		weights(1) = 0.478628670499366;
		coordinates(2) = 0.0;						weights(2) = 0.568888888888889;
		coordinates(3) = +0.538469310105683;		weights(3) = 0.478628670499366;
		coordinates(4) = +0.906179845938664;		weights(4) = 0.236926885056189;
		break;
	case 6:
		coordinates(0) = -0.932469514203152;		weights(0) = 0.171324492379170;
		coordinates(1) = -0.661209386466265;		weights(1) = 0.360761573048139;
		coordinates(2) = -0.238619186083197;		weights(2) = 0.467913934572691;
		coordinates(3) = +0.238619186083197;		weights(3) = 0.467913934572691;
		coordinates(4) = +0.661209386466265;		weights(4) = 0.360761573048139;
		coordinates(5) = +0.932469514203152;		weights(5) = 0.171324492379170;
		break;
	case 7:
		coordinates(0) = -0.949107912342759;		weights(0) = 0.129484966168870;
		coordinates(1) = -0.741531185599394;		weights(1) = 0.279705391489277;
		coordinates(2) = -0.405845151377397;		weights(2) = 0.381830050505119;
		coordinates(3) = 0.0;						weights(3) = 0.417959183673469;
		coordinates(4) = +0.405845151377397;		weights(4) = 0.381830050505119;
		coordinates(5) = +0.741531185599394;		weights(5) = 0.279705391489277;
		coordinates(6) = +0.949107912342759;		weights(6) = 0.129484966168870;
		break;
	case 8:
		coordinates(0) = -0.960289856497536;		weights(0) = 0.101228536290376;
		coordinates(1) = -0.796666477413627;		weights(1) = 0.222381034453374;
		coordinates(2) = -0.525532409916329;		weights(2) = 0.313706645877887;
		coordinates(3) = -0.183434642495650;		weights(3) = 0.362683783378362;
		coordinates(4) = +0.183434642495650;		weights(4) = 0.362683783378362;
		coordinates(5) = +0.525532409916329;		weights(5) = 0.313706645877887;
		coordinates(6) = +0.796666477413627;		weights(6) = 0.222381034453374;
		coordinates(7) = +0.960289856497536;		weights(7) = 0.101228536290376;
		break;
	default:
		throw std::out_of_range("Invalid number of integration points. Error in file " __FILE__);
	}
	return std::make_pair(coordinates, weights);
}

#endif // !LINE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
