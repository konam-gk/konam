#ifndef HEXAHEDRON_H
#define HEXAHEDRON_H

#include "hexahedron_gauss_legendre_integration_points.h"
#include "hexahedron_shape_functions.h"
#include "hexahedron_shape_functions_derivatives.h"
#include "vertex.h"



/*
 * Hexahedron8
 *
 *   4----------7
 *   |\         |\
 *   | \        | \
 *   |  \       |  \
 *   |   5------+---6
 *   |   |      |   |
 *   0---+------3   |
 *    \  |       \  |
 *     \ |        \ |
 *      \|         \|
 *       1----------2
 *
 *
 * Hexahedron20
 *
 *   4----19----7
 *   |\         |\
 *   | 16       | 18
 *  12  \       15 \
 *   |   5----17+---6
 *   |   |      |   |
 *   0---+-11---3   |
 *    \  13      \  14
 *     8 |        10|
 *      \|         \|
 *       1----9-----2
 *
 *
 * Hexahedron27
 *
 *   4----19----7
 *   |\         |\
 *   |16    25  | 18
 *  12  \ 24    15 \
 *   |   5----17+---6
 *   |21 |  26  | 23|
 *   0---+-11---3   |
 *    \ 13    22 \  14
 *     8 |  20    10|
 *      \|         \|
 *       1----9-----2
 *
 *
 * Hexahedron32
 *
 *   4---31---30----7
 *   |\             |\
 *   | 24           | 29
 *  20  \          23  \
 *   |   25         |   28
 *   |    \         |    \
 *  16     5---26---27----6
 *   |     |        |19   |
 *   |     |21      |     |
 *   0---15---14----3     22
 *    \    |         \    |
 *     8   |          13  |
 *      \  17          \  18
 *       9 |            12|
 *        \|             \|
 *         1---10---11----2
 */


using Hexahedron8V    = Hexahedron<8, 'E'>;
using Hexahedron8VMin = Hexahedron<8, 'M'>;

using Hexahedron20V    = Hexahedron<20, 'E'>;
using Hexahedron20VMin = Hexahedron<20, 'M'>;

using Hexahedron27V    = Hexahedron<27, 'E'>;
using Hexahedron27VMin = Hexahedron<27, 'M'>;

using Hexahedron32V    = Hexahedron<32, 'E'>;
using Hexahedron32VMin = Hexahedron<32, 'M'>;


template<unsigned int NVT = 8, char QRS = 'E'>
// NVT - number of element vertices
// QRS - quadrature rules ('E'-Exact (full), 'M'-Minimum)
class Hexahedron
{
public:

	static_assert(NVT == 8 || NVT == 20 || NVT == 27 || NVT == 32, "Invalid number of element vertices. "
		"Valid numbers are 8, 20, 27 and 32.");

	static_assert(QRS == 'E' || QRS == 'M',
		"Invalid quadrature rules. Valid integration rules are 'E' (Excact) and 'M' (Minimum).");


	// Constructors
	template<typename... T,
		typename = std::enable_if_t<std::conjunction_v<std::is_same<Vertex, T>...> && sizeof...(T) == NVT>>
		Hexahedron(unsigned int number, const T&...vertex)
		: m_number{ number }, m_node{ std::make_shared<Node>(node)... }
	{
	}


	template<typename T,
		typename = std::enable_if_t<std::is_same<std::vector_v<Vertex>, T>>>
		Hexahedron(unsigned int number, const T& vertices)
		: m_number{ number }
	{
		assert(vertices.size() == NVT);

		for (const auto& i : vertices)
			m_vertex.push_back(std::make_shared<Vertex>(i));
	}


	// calculate volume of element
	double volume()
	{
		double value{};

		// number of integration points
		auto const num_int_pts = this->integration_points_number();

		// Gauss-Legendre quadrature
		auto [abscissa, weights] = hexahedron_gauss_legendre_integration_points(num_int_pts);

		// matrix of shape function derivatives with respect to local coordinates
		konam_mat Nder(this->dimension(), this->vertices_number());

		// matrix of global vertices coordinates
		auto Coord = this->vertices_coordinates();

		// Jacobian matrix
		konam_mat Jac(this->dimension(), dimension());

		// variable of Jacobian determinant
		double dJ{};

		for (unsigned int i = 0; i < num_int_pts; ++i) {
			Nder = hexahedron_shape_functions_derivatives<NVT>(abscissa, i);
			Jac = Nder * Coord;
			dJ = this->calculate_Jacobian_determinant(Jac);
			value += dJ * weights(i);
		}

		return value;
	}


	unsigned int number() const
	{
		return m_number;
	}


	std::string type()
	{
		std::string type;
		switch (NVT) {
		case 8:
			type = "Hexahedron8";
			break;
		case 20:
			type = "Hexahedron20";
			break;
		case 27:
			type = "Hexahedron27";
			break;
		case 32:
			type = "Hexahedron32";
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


	unsigned int edges_number() const
	{
		return 12;
	}


	unsigned int faces_number() const
	{
		return 6;
	}


	std::shared_ptr<Vertex> get_vertex(int num) const
	{
		return this->m_vertex[num];
	}


	inline unsigned int integration_points_number()
	{
		static_assert(QRS == 'E' || QRS == 'M', "Invalid quadrature rules.");

		unsigned int value{};

		if constexpr (QRS == 'E')
			value = exact_quadrature();
		else
			value = minimum_quadrature();

		return value;
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


	inline double Jacobian_determinant()
	{
		return this->calculate_Jacobian_determinant(this->Jacobian_matrix());
	}


	konam_mat shape_functions_derivatives_matrix()
	{
		// number of integration points
		auto const num_int_pts = this->integration_points_number();

		// Gauss-Legendre quadrature -> abscissa
		auto abscissa = std::get<0>(hexahedron_gauss_legendre_integration_points(num_int_pts));

		// matrix of shape function derivatives with respect to local coordinates
		konam_mat Nder(this->dimension(), this->vertices_number(), 0.0);

		for (unsigned int i = 0; i < num_int_pts; ++i)
			Nder = hexahedron_shape_functions_derivatives<NVT>(abscissa, i);

		return Nder;
	}


	konam_mat vertices_coordinates()
	{
		const auto vnum = this->vertices_number();
		konam_mat coord(vnum, dimension());

		for (unsigned int i = 0; i < vnum; ++i)
			for (unsigned int j = 0; j < dimension(); ++j)
				coord(i, j) = m_vertex[i]->coordinate(j + 1);

		return coord;
	}


private:

	std::vector<std::shared_ptr<Vertex>> m_vertex;
	unsigned int m_number;


	inline double calculate_Jacobian_determinant(const konam_mat& Jac)
	{
		// The determinant of the Jacobian matrix |J| is used for the transformation
		// of integrals from the global coordinate system to the local coordinate system.

		double dJ = std::pow(Jac(0, 0) * Jac(1, 1) - Jac(0, 1) * Jac(1, 0), 2) +
			std::pow(Jac(0, 2) * Jac(1, 0) - Jac(0, 0) * Jac(1, 2), 2) +
			std::pow(Jac(0, 1) * Jac(1, 2) - Jac(0, 2) * Jac(1, 1), 2);

		return std::sqrt(dJ);
	}


	inline int exact_quadrature()	// preveri
	{
		int value{};

		switch (NVT) {
		case 8:
			value = 8;
			break;
		case 20:
			value = 27;
			break;
		case 27:
			value = 64;
			break;
		case 32:
			value = 125;
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
		}
		return value;
	}


	inline int minimum_quadrature()	// preveri
	{
		int value{};

		switch (NVT) {
		case 8:
			value = 1;
			break;
		case 20:
			value = 8;
			break;
		case 27:
			value = 27;
			break;
		case 32:
			value = 64;
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
		}
		return value;
	}

};


#endif // !HEXAHEDRON_H