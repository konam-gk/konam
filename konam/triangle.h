/* https://www.cppstories.com/2014/05/vector-of-objects-vs-vector-of-pointers/ */

//#ifndef TRIANGLE_H
//#define TRIANGLE_H
//
//#include "triangle_gauss_legendre_integration_points.h"
//#include "triangle_shape_functions.h"
//#include "triangle_shape_functions_derivatives.h"
//#include "vertex.h"
//
//
///*
// * Triangle3
// *
// *   2
// *   |`\
// *   |  `\
// *   |    `\
// *   |      `\
// *   |        `\
// *   0----------1
// *
// *
// * Triangle6
// *
// *   2
// *   |`\
// *   |  `\
// *   5    `4
// *   |      `\
// *   |        `\
// *   0-----3----1
// *
// *
// * Triangle10
// *
// *   2
// *   |`\
// *   7  `6
// *   |    `\
// *   8   9  `5
// *   |        `\
// *   0---3--4---1
// *
// *
// * Triangle15
// *
// *   2
// *   |`\
// *   9  `8
// *   |    `\
// *  10  14  `7
// *   |        `\
// *  11  12  13  `6
// *   |            `\
// *   0---3---4---5---1
// *
// */
//
//
//using Triangle3V = Triangle<3>;
//using Triangle6V = Triangle<6>;
//using Triangle10V = Triangle<10>;
//using Triangle15V = Triangle<15>;
//
//
//template<unsigned int NVT>
//// NVT - number of element vertices
//class Triangle
//{
//public:
//
//	static_assert(NVT == 3 || NVT == 6 || NVT == 10 || NVT == 15, "Invalid number of element vertices. "
//		"Valid numbers are 3, 6, 10 and 15.");
//
//
//	// Constructors
//	template<typename... T,
//		typename = std::enable_if_t<std::conjunction_v<std::is_same<Vertex, T>...> && sizeof...(T) == NVT>>
//		Triangle(unsigned int number, const T&...vertex)
//		: m_number{ number }, m_vertex{ std::make_shared<Vertex>(vertex)... }
//	{
//	}
//
//
//	template<typename T,
//		typename = std::enable_if_t<std::is_same_v<std::vector<Vertex>, T>>>
//		Triangle(unsigned int number, const T& vertices)
//		: m_number{ number }
//	{
//		assert(vertices.size() == NVT);
//
//		for (const auto& i : vertices)
//			m_vertex.push_back(std::make_shared<Vertex>(i));
//	}
//
//
//	// calculate area of element
//	double area()
//	{
//		return 0.5 * this->Jacobian_determinant();
//	}
//
//
//	int number() const
//	{
//		return this->m_number;
//	}
//
//
//	std::string type()
//	{
//		std::string type;
//		switch (NVT) {
//		case 3:
//			type = "Triangle3";
//			break;
//		case 6:
//			type = "Triangle6";
//			break;
//		case 10:
//			type = "Triangle10";
//			break;
//		case 15:
//			type = "Triangle15";
//			break;
//		default:
//			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
//		}
//		return type;
//	}
//
//
//	unsigned int dimension() const
//	{
//		return 3;
//	}
//
//
//	std::size_t vertices_number() const
//	{
//		return this->m_vertex.size();
//	}
//
//
//	unsigned int edges_number() const	// !!!
//	{
//		return 3;
//	}
//
//
//	unsigned int faces_number() const
//	{
//		return 1;
//	}
//
//
//	std::shared_ptr<Vertex> get_vertex(int num) const
//	{
//		return this->m_vertex[num];
//	}
//
//
//	inline unsigned int integration_points_number()
//	{
//		return this->exact_quadrature();
//	}
//
//
//	konam_mat Jacobian_matrix()
//	{
//		// matrix of shape function derivatives - Nder
//		auto Nder = this->shape_functions_derivatives_matrix();
//
//		// matrix of global vertices coordinates
//		auto Coord = this->vertices_coordinates();
//
//		// Jacobian matrix
//		konam_mat Jacobian = prod(Nder, Coord);
//
//		return Jacobian;
//	}
//
//
//	double Jacobian_determinant()
//	{
//		// The determinant of the Jacobian matrix |J| is used for the transformation
//		// of integrals from the global coordinate system to the local coordinate system.
//		auto Jac = this->Jacobian_matrix();
//
//		double dJ = std::pow(Jac(0, 0) * Jac(1, 1) - Jac(0, 1) * Jac(1, 0), 2) +
//			std::pow(Jac(0, 2) * Jac(1, 0) - Jac(0, 0) * Jac(1, 2), 2) +
//			std::pow(Jac(0, 1) * Jac(1, 2) - Jac(0, 2) * Jac(1, 1), 2);
//
//		return std::sqrt(dJ);
//	}
//
//
//	konam_mat shape_functions_derivatives_matrix()
//	{
//		// number of integration points
//		auto const num_int_pts = this->integration_points_number();
//
//		// Gauss-Legendre quadrature
//		auto abscissa = std::get<0>(triangle_gauss_legendre_integration_points(num_int_pts));
//
//		// matrix of shape function derivatives with respect to local coordinates
//		konam_mat Nder(this->dimension(), this->vertices_number(), 0.0);
//
//		for (unsigned int i = 0; i < num_int_pts; ++i)
//			Nder = triangle_shape_functions_derivatives<NVT>(abscissa, i);
//
//		return Nder;
//	}
//
//
//	konam_mat vertices_coordinates()
//	{
//		const auto vnum = this->vertices_number();
//		konam_mat coord(vnum, dimension());
//
//		for (unsigned int i = 0; i < vnum; ++i)
//			for (unsigned int j = 0; j < dimension(); ++j)
//				coord(i, j) = this->m_vertex[i]->coordinate(j + 1);
//
//		return coord;
//	}
//
//
//private:
//
//	std::vector<std::shared_ptr<Vertex>> m_vertex;
//	unsigned int m_number;
//
//
//	inline int exact_quadrature()
//	{
//		int value{};
//
//		switch (NVT) {
//		case 3:
//			value = 1;
//			break;
//		case 6:
//			value = 3;
//			break;
//		case 10:
//			value = 4;
//			break;
//		case 15:
//			value = 7;
//			break;
//		default:
//			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
//		}
//		return value;
//	}
//
//
//	inline int minimum_quadrature()
//	{
//		int value{};
//
//		switch (NVT) {
//		case 3:
//			value = 1;
//			break;
//		case 6:
//			value = 3;
//			break;
//		case 10:
//			value = 4;
//			break;
//		case 15:
//			value = 7;
//			break;
//		default:
//			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
//		}
//		return value;
//	}
//
//};
//
//
//#endif // !TRIANGLE_H


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "triangle_gauss_legendre_integration_points.h"
#include "triangle_shape_functions.h"
#include "triangle_shape_functions_derivatives.h"
#include "vertex.h"


/*
 * Triangle3
 *
 *   2
 *   |`\
 *   |  `\
 *   |    `\
 *   |      `\
 *   |        `\
 *   0----------1
 *
 *
 * Triangle6
 *
 *   2
 *   |`\
 *   |  `\
 *   5    `4
 *   |      `\
 *   |        `\
 *   0-----3----1
 *
 *
 * Triangle10
 *
 *   2
 *   |`\
 *   7  `6
 *   |    `\
 *   8   9  `5
 *   |        `\
 *   0---3--4---1
 *
 *
 * Triangle15
 *
 *   2
 *   |`\
 *   9  `8
 *   |    `\
 *  10  14  `7
 *   |        `\
 *  11  12  13  `6
 *   |            `\
 *   0---3---4---5---1
 *
 */


using Triangle3V = Triangle<3>;
using Triangle6V = Triangle<6>;
using Triangle10V = Triangle<10>;
using Triangle15V = Triangle<15>;


template<unsigned int NVT>
// NVT - number of element vertices
class Triangle
{
public:

	static_assert(NVT == 3 || NVT == 6 || NVT == 10 || NVT == 15, "Invalid number of element vertices. "
		"Valid numbers are 3, 6, 10 and 15.");


	// Constructors
	template<typename... T,
		typename = std::enable_if_t<std::conjunction_v<std::is_same<Vertex, T>...> && sizeof...(T) == NVT>>
		Triangle(unsigned int number, const T&...vertex)
		: m_number{ number }, m_vertex{ vertex... }
	{
	}


	template<typename T,
		typename = std::enable_if_t<std::is_same_v<std::vector<Vertex>, T>>>
		Triangle(unsigned int number, const T& vertices)
		: m_number{ number }, m_vertex{ vertices }
	{
		assert(vertices.size() == NVT);
	}


	// calculate area of element
	double area()
	{
		return 0.5 * this->Jacobian_determinant();
	}


	int number() const
	{
		return this->m_number;
	}


	std::string type()
	{
		std::string type;
		switch (NVT) {
		case 3:
			type = "Triangle3";
			break;
		case 6:
			type = "Triangle6";
			break;
		case 10:
			type = "Triangle10";
			break;
		case 15:
			type = "Triangle15";
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
		}
		return type;
	}


	unsigned int dimension() const
	{
		return 3;
	}


	std::size_t vertices_number() const
	{
		return this->m_vertex.size();
	}


	unsigned int edges_number() const	// !!!
	{
		return 3;
	}


	unsigned int faces_number() const
	{
		return 1;
	}


	inline auto get_vertex(int num) const
	{
		return this->m_vertex[num];
	}


	inline unsigned int integration_points_number()
	{
		return this->exact_quadrature();
	}


	konam_mat Jacobian_matrix()
	{
		// matrix of shape function derivatives - Nder
		auto Nder = this->shape_functions_derivatives_matrix();

		// matrix of global vertices coordinates
		auto Coord = this->vertices_coordinates();

		// Jacobian matrix
		konam_mat Jacobian = prod(Nder, Coord);

		return Jacobian;
	}


	double Jacobian_determinant()
	{
		// The determinant of the Jacobian matrix |J| is used for the transformation
		// of integrals from the global coordinate system to the local coordinate system.
		auto Jac = this->Jacobian_matrix();

		double dJ = std::pow(Jac(0, 0) * Jac(1, 1) - Jac(0, 1) * Jac(1, 0), 2) +
			std::pow(Jac(0, 2) * Jac(1, 0) - Jac(0, 0) * Jac(1, 2), 2) +
			std::pow(Jac(0, 1) * Jac(1, 2) - Jac(0, 2) * Jac(1, 1), 2);

		return std::sqrt(dJ);
	}


	konam_mat shape_functions_derivatives_matrix()
	{
		// number of integration points
		auto const num_int_pts = this->integration_points_number();

		// Gauss-Legendre quadrature
		auto abscissa = std::get<0>(triangle_gauss_legendre_integration_points(num_int_pts));

		// matrix of shape function derivatives with respect to local coordinates
		konam_mat Nder(this->dimension(), this->vertices_number(), 0.0);

		for (unsigned int i = 0; i < num_int_pts; ++i)
			Nder = triangle_shape_functions_derivatives<NVT>(abscissa, i);

		return Nder;
	}


	konam_mat vertices_coordinates()
	{
		const auto vnum = this->vertices_number();
		konam_mat coord(vnum, dimension());

		for (unsigned int i = 0; i < vnum; ++i)
			for (unsigned int j = 0; j < dimension(); ++j)
				coord(i, j) = this->m_vertex[i].coordinate(j + 1);

		return coord;
	}


private:

	std::vector<Vertex> m_vertex;
	unsigned int m_number;


	inline int exact_quadrature()
	{
		int value{};

		switch (NVT) {
		case 3:
			value = 1;
			break;
		case 6:
			value = 3;
			break;
		case 10:
			value = 4;
			break;
		case 15:
			value = 7;
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
		}
		return value;
	}


	inline int minimum_quadrature()
	{
		int value{};

		switch (NVT) {
		case 3:
			value = 1;
			break;
		case 6:
			value = 3;
			break;
		case 10:
			value = 4;
			break;
		case 15:
			value = 7;
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
		}
		return value;
	}

};


#endif // !TRIANGLE_H