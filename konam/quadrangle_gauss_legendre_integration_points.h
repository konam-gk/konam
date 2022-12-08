// The coordinates and related weights for isoparametric Quadrangle Domains
// using Gauss-Legendre quadrature

#ifndef QUADRANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
#define QUADRANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H

#include <cmath>
#include <stdexcept>

#include "konam_array.h"


auto quadrangle_gauss_legendre_integration_points(const int num_int_pts)
{
	// num_int_pts - number of integration points
	const int dim{ 2 };
	konam_mat coordinates(num_int_pts, dim);
	konam_vec weights(num_int_pts);

	switch (num_int_pts) {
	case 1:
		// point 1
		coordinates(0, 0) = 0.0;						weights(0) = 4.0;
		coordinates(0, 1) = 0.0;
		break;
	case 4:
		// point 1
		coordinates(0, 0) = -std::sqrt(1.0 / 3.0);		weights(0) = 1.0;
		coordinates(0, 1) = -std::sqrt(1.0 / 3.0);     
		// point 2 
		coordinates(1, 0) = +std::sqrt(1.0 / 3.0);		weights(1) = 1.0;
		coordinates(1, 1) = -std::sqrt(1.0 / 3.0);     
		// point 3										
		coordinates(2, 0) = +std::sqrt(1.0 / 3.0);		weights(2) = 1.0;
		coordinates(2, 1) = +std::sqrt(1.0 / 3.0);
		// point 4
		coordinates(3, 0) = -std::sqrt(1.0 / 3.0);		weights(3) = 1.0;
		coordinates(3, 1) = +std::sqrt(1.0 / 3.0);
		break;
	case 9:
		// point 1
		coordinates(0, 0) = -std::sqrt(0.6);			weights(0) = 25.0 / 81.0;
		coordinates(0, 1) = -std::sqrt(0.6);           
		// point 2
		coordinates(1, 0) = 0.0;						weights(1) = 40.0 / 81.0; 
		coordinates(1, 1) = -std::sqrt(0.6);            
		// point 3
		coordinates(2, 0) = +std::sqrt(0.6);			weights(2) = 25.0 / 81.0;
		coordinates(2, 1) = -std::sqrt(0.6);           
		// point 4
		coordinates(3, 0) = -std::sqrt(0.6);			weights(3) = 40.0 / 81.0; 
		coordinates(3, 1) = 0.0;                       
		// point 5
		coordinates(4, 0) = 0.0;						weights(4) = 64.0 / 81.0; 
		coordinates(4, 1) = 0.0;
		// point 6
		coordinates(5, 0) = +std::sqrt(0.6);			weights(5) = 40.0 / 81.0;
		coordinates(5, 1) = 0.0;
		// point 7
		coordinates(6, 0) = -std::sqrt(0.6);			weights(6) = 25.0 / 81.0;
		coordinates(6, 1) = +std::sqrt(0.6);
		// point 8
		coordinates(7, 0) = 0.0;						weights(7) = 40.0 / 81.0;
		coordinates(7, 1) = +std::sqrt(0.6);
		// point 9
		coordinates(8, 0) = +std::sqrt(0.6);			weights(8) = 25.0 / 81.0;
		coordinates(8, 1) = +std::sqrt(0.6);
		break;
	case 16:
		// point 1
		coordinates(0, 0) = -std::sqrt((3.0 + 2.0*std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(0, 1) = -std::sqrt((3.0 + 2.0*std::sqrt(6.0 / 5.0)) / 7.0);
		weights(0) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);
		// point 2
		coordinates(1, 0) = -std::sqrt((3.0 + 2.0*std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(1, 1) = -std::sqrt((3.0 - 2.0*std::sqrt(6.0 / 5.0)) / 7.0);
		weights(1) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 3
		coordinates(2, 0) = -std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(2, 1) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(2) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 4
		coordinates(3, 0) = -std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(3, 1) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(3) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);
		// point 5
		coordinates(4, 0) = -std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(4, 1) = -std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(4) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);
		// point 6
		coordinates(5, 0) = -std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(5, 1) = -std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(5) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 7
		coordinates(6, 0) = -std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(6, 1) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(6) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 8
		coordinates(7, 0) = -std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(7, 1) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(7) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);
		// point 9
		coordinates(8, 0) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(8, 1) = -std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(8) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);
		// point 10
		coordinates(9, 0) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(9, 1) = -std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(9) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 11
		coordinates(10, 0) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(10, 1) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(10) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 12
		coordinates(11, 0) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(11, 1) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(11) = (0.5 + std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);
		// point 13
		coordinates(12, 0) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(12, 1) = -std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(12) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);
		// point 14
		coordinates(13, 0) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(13, 1) = -std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(13) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 15
		coordinates(14, 0) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(14, 1) = +std::sqrt((3.0 - 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(14) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 + std::sqrt(5.0 / 6.0) / 6.0);
		// point 16
		coordinates(15, 0) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		coordinates(15, 1) = +std::sqrt((3.0 + 2.0 * std::sqrt(6.0 / 5.0)) / 7.0);
		weights(15) = (0.5 - std::sqrt(5.0 / 6.0) / 6.0) * (0.5 - std::sqrt(5.0 / 6.0) / 6.0);		
		break;
	default:
		throw std::out_of_range("Invalid number of integration points. Error in file " __FILE__);
	}
	return std::make_pair(coordinates, weights);
}

#endif // !QUADRANGLE_GAUSS_LEGENDRE_INTEGRATION_POINTS_H
