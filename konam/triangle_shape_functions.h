#ifndef TRIANGLE_SHAPE_FUNCTIONS_H
#define TRIANGLE_SHAPE_FUNCTIONS_H


#include "konam_array.h"


template<typename Type>
void triangle_shape_functions(konam_vec& func, Type& type, const konam_mat& abscissa, const int i)
{
	// natural coordinates
	auto xi = abscissa(i, 0);
	auto eta = abscissa(i, 1);

	// natural triangle coordinates
	auto L1 = 1.0 - xi - eta;
	auto L2 = xi;
	auto L3 = eta;


	switch (type) {
	case Type::Triangle3:
		// vertex 0
		func(0) = L1;
		// vertex 1
		func(1) = L2;
		// vertex 3
		func(2) = L3;
		break;
	case Type::Triangle6:
		// vertex 0
		func(0) = (2.0 * L1 - 1.0) * L1;
		// vertex 1
		func(1) = (2.0 * L2 - 1.0) * L2;
		// vertex 2
		func(2) = (2.0 * L3 - 1.0) * L3;
		// vertex 3
		func(3) = 4.0 * L1 * L2;
		// vertex 4
		func(4) = 4.0 * L2 * L3;
		// vertex 5
		func(5) = 4.0 * L1 * L3;
		break;
	case Type::Triangle10:
		// vertex 0
		func(0) = 0.5 * L1 * (3.0 * L1 - 1.0) * (3.0 * L1 - 2.0);
		// vertex 1
		func(1) = 0.5 * L2 * (3.0 * L2 - 1.0) * (3.0 * L2 - 2.0);
		// vertex 2
		func(2) = 0.5 * L3 * (3.0 * L3 - 1.0) * (3.0 * L3 - 2.0);
		// vertex 3
		func(3) = 4.5 * (3.0 * L1 - 1.0) * L1 * L2;
		// vertex 4
		func(4) = 4.5 * (3.0 * L2 - 1.0) * L1 * L2;
		// vertex 5
		func(5) = 4.5 * (3.0 * L2 - 1.0) * L2 * L3;
		// vertex 6
		func(6) = 4.5 * (3.0 * L3 - 1.0) * L2 * L3;
		// vertex 7
		func(7) = 4.5 * (3.0 * L3 - 1.0) * L3 * L1;
		// vertex 8
		func(8) = 4.5 * (3.0 * L1 - 1.0) * L3 * L1;
		// vertex 9
		func(9) = 27.0 * L1 * L2 * L3;
	case Type::Triangle15:
		// vertex 0
		func(0) = (1.0 / 6.0) * L1 * (4.0 * L1 - 1.0) * (4.0 * L1 - 2.0) * (4.0 * L1 - 3.0);
		// vertex 1
		func(1) = (1.0 / 6.0) * L2 * (4.0 * L2 - 1.0) * (4.0 * L2 - 2.0) * (4.0 * L2 - 3.0);
		// vertex 2
		func(2) = (1.0 / 6.0) * L3 * (4.0 * L3 - 1.0) * (4.0 * L3 - 2.0) * (4.0 * L3 - 3.0);
		// vertex 3
		func(3) = (8.0 / 3.0) * L1 * (4.0 * L1 - 1.0) * (4.0 * L1 - 2.0) * L2;
		// vertex 4
		func(4) = L1 * (8.0 * L1 - 2.0) * L2 * (8.0 * L2 - 2.0);
		// vertex 5
		func(5) = (8.0 / 3.0) * L1 * L2 * (4.0 * L2 - 1.0) * (4.0 * L2 - 2.0);
		// vertex 6
		func(6) = (8.0 / 3.0) * L2 * L3 * (4.0 * L2 - 1.0) * (4.0 * L2 - 2.0);
		// vertex 7
		func(7) = L2 * (8.0 * L2 - 2.0) * L3 * (8.0 * L3 - 2.0);
		// vertex 8
		func(8) = (8.0 / 3.0) * L2 * L3 * (4.0 * L3 - 1.0) * (4.0 * L3 - 2.0);
		// vertex 9
		func(9) = (8.0 / 3.0) * L1 * L3 * (4.0 * L3 - 1.0) * (4.0 * L3 - 2.0);
		// vertex 10
		func(10) = L1 * (8.0 * L1 - 2.0) * L3 * (8.0 * L3 - 2.0);
		// vertex 11
		func(11) = (8.0 / 3.0) * L1 * L3 * (4.0 * L1 - 1.0) * (4.0 * L1 - 2.0);
		// vertex 12
		func(12) = 16.0 * L1 * L2 * L3 * (8.0 * L1 - 2.0);
		// vertex 13
		func(13) = 16.0 * L1 * L2 * L3 * (8.0 * L2 - 2.0);
		// vertex 14
		func(14) = 16.0 * L1 * L2 * L3 * (8.0 * L3 - 2.0);
	}

}


#endif // !TRIANGLE_SHAPE_FUNCTIONS_H