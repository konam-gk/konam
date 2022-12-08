#ifndef LINE_SHAPE_FUNCTIONS_H
#define LINE_SHAPE_FUNCTIONS_H


#include "konam_array.h"


template<typename Type>
void line_shape_functions(konam_vec& func, Type& type, const konam_mat& abscissa, const int i)
{
	// natural coordinate
	auto xi = abscissa(i);	

	// help variable
	auto xi2 = xi * xi;	


	switch (type) {
	case Type::Line2:
		// vertex 0
		func(0) = 0.5 * (1.0 - xi);
		// vertex 1
		func(1) = 0.5 * (1.0 + xi);
		break;
	case Type::Line3:
		// vertex 0
		func(0) = 0.5 * xi * (xi - 1.0);
		// vertex 1
		func(1) = (1.0 - xi2);
		// vertex 2
		func(2) = 0.5 * xi * (xi + 1.0);
		break;
	case Type::Line4:
		// vertex 0
		func(0) = -(9.0 / 16.0) * (xi2 - 1.0 / 9.0) * (xi - 1.0);
		// vertex 1
		func(1) = -(27.0 / 16.0) * (xi + 1.0 / 3.0) * (xi2 - 1.0);
		// vertex 2
		func(2) = (9.0 / 16.0) * (xi2 - 1.0 / 9.0) * (xi + 1.0);
		// vertex 3
		func(3) = (27.0 / 16.0) * (xi - 1.0 / 3.0) * (xi2 - 1.0);
		break;
	case Type::Line5:
		func(0) = (2.0 / 3.0) * xi * (xi + 1.0 / 2.0) * (xi - 1.0 / 2.0) * (xi - 1.0);
		func(1) = -(8.0 / 3.0) * xi * (xi + 1.0) * (xi - 0.5) * (xi - 1.0);
		func(2) = 4.0 * xi * (xi + 0.5) * (xi - 0.5) * (xi - 1.0);
		func(3) = -(8.0 / 3.0) * xi * (xi + 1.0) * (xi + 0.5) * (xi - 1.0);
		func(4) = (2.0 / 3.0) * xi * (xi + 1.0 / 2.0) * (xi - 1.0 / 2.0) * (xi + 1.0);
	}

}


#endif // !LINE_SHAPE_FUNCTIONS_H