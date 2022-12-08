#ifndef QUADRANGLE_SHAPE_FUNCTIONS_H
#define QUADRANGLE_SHAPE_FUNCTIONS_H


#include "konam_array.h"


template<typename Type>
void quadrangle_shape_functions(konam_vec& func, Type& type, const konam_mat& abscissa, const int i)
{
	// natural coordinates
	auto xi = abscissa(i, 0);
	auto eta = abscissa(i, 1);

	// help variables
	auto xi2 = xi * xi;
	auto eta2 = eta * eta;


	switch (this->m_element_type) {
	case Type::Quadrangle4:
		// vertex 0
		func(0) = 0.25 * (1.0 - xi) * (1 - eta);
		// vertex 1
		func(1) = 0.25 * (1.0 + xi) * (1 - eta);
		// vertex 2
		func(2) = 0.25 * (1.0 + xi) * (1 + eta);
		// vertex 3
		func(3) = 0.25 * (1.0 - xi) * (1 + eta);
		break;
	case Type::Quadrangle8:
		// vertex 0
		func(0) = (-1.0 / 4.0) * (1.0 - xi) * (1.0 - eta) * (xi + eta + 1.0);
		// vertex 1
		func(1) = (1.0 / 4.0) * (1.0 + xi) * (1.0 - eta) * (xi - eta - 1.0);
		// vertex 2
		func(2) = (1.0 / 4.0) * (1.0 + xi) * (1.0 + eta) * (xi + eta - 1.0);
		// vertex 3
		func(3) = (-1.0 / 4.0) * (1.0 - xi) * (1.0 + eta) * (xi - eta + 1.0);
		// vertex 4
		func(4) = (1.0 / 2.0) * (1.0 - eta) * (1.0 - xi2);
		// vertex 5
		func(5) = (1.0 / 2.0) * (1.0 + xi) * (1.0 - eta2);
		// vertex 6
		func(6) = (1.0 / 2.0) * (1.0 + eta) * (1.0 - xi2);
		// vertex 7
		func(7) = (1.0 / 2.0) * (1.0 - xi) * (1.0 - eta2);
		break;
	case Type::Quadrangle9:
		// vertex 0
		func(0) = 0.25 * (xi2 - xi) * (eta2 - eta);
		// vertex 1
		func(1) = 0.25 * (xi2 + xi) * (eta2 - eta);
		// vertex 2
		func(2) = 0.25 * (xi2 + xi) * (eta2 + eta);
		// vertex 3
		func(3) = 0.25 * (xi2 - xi) * (eta2 + eta);
		// vertex 4
		func(4) = 0.5 * (eta2 - eta) * (1.0 - xi2);
		// vertex 5
		func(5) = 0.5 * (xi2 + xi) * (1.0 - eta2);
		// vertex 6
		func(6) = 0.5 * (eta2 + eta) * (1.0 - xi2);
		// vertex 7
		func(7) = 0.5 * (xi2 - xi) * (1.0 - eta2);
		// vertex 8
		func(8) = (1.0 - xi2) * (1.0 - eta2);
		break;
	case Type::Quadrangle12:
		// vertex 0
		func(0) = (1.0 / 32.0) * (1.0 - xi) * (1.0 - eta) * (9.0 * (xi2 + eta2) - 10.0);
		// vertex 1
		func(1) = (1.0 / 32.0) * (1.0 + xi) * (1.0 - eta) * (9.0 * (xi2 + eta2) - 10.0);
		// vertex 2
		func(2) = (1.0 / 32.0) * (1.0 + xi) * (1.0 + eta) * (9.0 * (xi2 + eta2) - 10.0);
		// vertex 3
		func(3) = (1.0 / 32.0) * (1.0 - xi) * (1.0 + eta) * (9.0 * (xi2 + eta2) - 10.0);
		// vertex 4
		func(4) = (9.0 / 32.0) * (1.0 - eta) * (1.0 - xi2) * (1.0 - 3.0 * xi);
		// vertex 5
		func(5) = (9.0 / 32.0) * (1.0 - eta) * (1.0 - xi2) * (1.0 + 3.0 * xi);
		// vertex 6
		func(6) = (9.0 / 32.0) * (1.0 + xi) * (1.0 - eta2) * (1.0 - 3.0 * eta);
		// vertex 7
		func(7) = (9.0 / 32.0) * (1.0 + xi) * (1.0 - eta2) * (1.0 + 3.0 * eta);
		// vertex 8
		func(8) = (9.0 / 32.0) * (1.0 + eta) * (1.0 - xi2) * (1.0 + 3.0 * xi);
		// vertex 9
		func(9) = (9.0 / 32.0) * (1.0 + eta) * (1.0 - xi2) * (1.0 - 3.0 * xi);
		// vertex 10
		func(10) = (9.0 / 32.0) * (1.0 - xi) * (1.0 - eta2) * (1.0 + 3.0 * eta);
		// vertex 11
		func(11) = (9.0 / 32.0) * (1.0 - xi) * (1.0 - eta2) * (1.0 - 3.0 * eta);
		break;
	case Type::Quadrangle16:
		// vertex 0
		func(0) = (81.0 / 256.0) * (1.0 - xi) * (1.0 - eta) * ((1.0 / 9.0) - xi2) * ((1.0 / 9.0) - eta2);
		// vertex 1
		func(1) = (81.0 / 256.0) * (1.0 + xi) * (1.0 - eta) * ((1.0 / 9.0) - xi2) * ((1.0 / 9.0) - eta2);
		// vertex 2
		func(2) = (81.0 / 256.0) * (1.0 + xi) * (1.0 + eta) * ((1.0 / 9.0) - xi2) * ((1.0 / 9.0) - eta2);
		// vertex 3
		func(3) = (81.0 / 256.0) * (1.0 - xi) * (1.0 + eta) * ((1.0 / 9.0) - xi2) * ((1.0 / 9.0) - eta2);
		// vertex 4
		func(4) = (243.0 / 256.0) * (1.0 - xi2) * (eta2 - (1.0 / 9.0)) * ((1.0 / 3.0) - xi) * (1.0 - eta);
		// vertex 5
		func(5) = (243.0 / 256.0) * (1.0 - xi2) * (eta2 - (1.0 / 9.0)) * ((1.0 / 3.0) + xi) * (1.0 - eta);
		// vertex 6
		func(6) = (243.0 / 256.0) * (1.0 - eta2) * (xi2 - (1.0 / 9.0)) * ((1.0 / 3.0) - eta) * (1.0 + xi);
		// vertex 7
		func(7) = (243.0 / 256.0) * (1.0 - eta2) * (xi2 - (1.0 / 9.0)) * ((1.0 / 3.0) + eta) * (1.0 + xi);
		// vertex 8
		func(8) = (243.0 / 256.0) * (1.0 - xi2) * (eta2 - (1.0 / 9.0)) * ((1.0 / 3.0) + xi) * (1.0 + eta);
		// vertex 9
		func(9) = (243.0 / 256.0) * (1.0 - xi2) * (eta2 - (1.0 / 9.0)) * ((1.0 / 3.0) - xi) * (1.0 + eta);
		// vertex 10
		func(10) = (243.0 / 256.0) * (1.0 - eta2) * (xi2 - (1.0 / 9.0)) * ((1.0 / 3.0) + eta) * (1.0 - xi);
		// vertex 11
		func(11) = (243.0 / 256.0) * (1.0 - eta2) * (xi2 - (1.0 / 9.0)) * ((1.0 / 3.0) - eta) * (1.0 - xi);
		// vertex 12
		func(12) = (729.0 / 256.0) * (1.0 - xi2) * (1.0 - eta2) * ((1.0 / 3.0) - xi) * ((1.0 / 3.0) - eta);
		// vertex 13
		func(13) = (729.0 / 256.0) * (1.0 - xi2) * (1.0 - eta2) * ((1.0 / 3.0) + xi) * ((1.0 / 3.0) - eta);
		// vertex 14
		func(14) = (729.0 / 256.0) * (1.0 - xi2) * (1.0 - eta2) * ((1.0 / 3.0) + xi) * ((1.0 / 3.0) + eta);
		// vertex 15
		func(15) = (729.0 / 256.0) * (1.0 - xi2) * (1.0 - eta2) * ((1.0 / 3.0) - xi) * ((1.0 / 3.0) + eta);
	}

}


#endif // !QUADRANGLE_SHAPE_FUNCTIONS_H