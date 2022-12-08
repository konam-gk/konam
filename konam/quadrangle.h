#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include "quadrangle_gauss_legendre_integration_points.h"
#include "quadrangle_shape_functions.h"
#include "quadrangle_shape_functions_derivatives.h"
#include "vertex.h"



/*
 * Quadrangle4
 *
 *   3-----------2
 *   |	         |
 *   |           |
 *   |           |
 *   |           |
 *   |           |
 *   0-----------1
 *
 *
 * Quadrangle8
 *
 *   3-----6-----2
 *   |           |
 *   |           |
 *   7           5
 *   |           |
 *   |           |
 *   0-----4-----1
 *
 *
 * Quadrangle9
 *
 *   3-----6-----2
 *   |           |
 *   |           |
 *   7     8     5
 *   |           |
 *   |           |
 *   0-----4-----1
 *
 *
 * Quadrangle12
 *
 *   3---9---8---2
 *   |           |
 *  10           7
 *   |           |
 *  11           6
 *   |           |
 *   0---4---5---1
 *
 *
 * Quadrangle16
 *
 *   3---9---8---2
 *   |           |
 *  10  15  14   7
 *   |           |
 *  11  12  13   6
 *   |           |
 *   0---4---5---1
 *
 */


using Quadrangle4V    = Quadrangle<4, 'E'>;
using Quadrangle4VMin = Quadrangle<4, 'M'>;

using Quadrangle8V    = Quadrangle<8, 'E'>;
using Quadrangle8VMin = Quadrangle<8, 'M'>;

using Quadrangle9V    = Quadrangle<9, 'E'>;
using Quadrangle9VMin = Quadrangle<9, 'M'>;

using Quadrangle12V    = Quadrangle<12, 'E'>;
using Quadrangle12VMin = Quadrangle<12, 'M'>;

using Quadrangle16V    = Quadrangle<16, 'E'>;
using Quadrangle16VMin = Quadrangle<16, 'M'>;


template<unsigned int NVT = 4, char QRS = 'E'>
// NVT - number of element vertices
// QRS - quadrature rules ('E'-Exact (full), 'M'-Minimum)
class Quadrangle
{
public:

	static_assert(NVT == 4 || NVT == 8 || NVT == 9 || NVT == 12 || NVT == 16, "Invalid number of element vertices. "
		"Valid numbers are 4, 8, 9, 12 and 16.");

	static_assert(QRS == 'E' || QRS == 'M',
		"Invalid quadrature rules. Valid integration rules are 'E' (Excact) and 'M' (Minimum).");


	// Constructors
	template<typename... T,
		typename = std::enable_if_t<std::conjunction_v<std::is_same<Vertex, T>...> && sizeof...(T) == NVT>>
		Quadrangle(unsigned int number, const T&...vertex)
		: m_number{ number }, m_vertex{ std::make_shared<Vertex>(vertex)... }
	{
	}


	template<typename T,
		typename = std::enable_if_t<std::is_same_v<std::vector<Vertex>, T>>>
		Quadrangle(unsigned int number, const T& vertices)
		: m_number{ number }
	{
		assert(vertices.size() == NVT);

		for (const auto& i : vertices)
			m_vertex.push_back(std::make_shared<Vertex>(i));
	}


	// calculate area of element
	double area()
	{
		double value{};

		// number of integration points
		auto const num_int_pts = this->integration_points_number();

		// Gauss-Legendre quadrature
		auto [abscissa, weights] = quadrangle_gauss_legendre_integration_points(num_int_pts);

		// matrix of shape function derivatives with respect to local coordinates
		konam_mat Nder(this->dimension(), this-vertices_number());

		// vector of global vertices coordinates
		auto Coord = this->vertices_coordinates();

		// Jacobian matrix
		konam_mat Jac(this->dimension(), dimension());

		// variable of Jacobian determinant
		double dJ{};

		for (unsigned int i = 0; i < num_int_pts; ++i) {
			Nder = quadrangle_shape_functions_derivatives<NVT>(abscissa, i);
			Jac = Nder * Coord;
			dJ = this->calculate_Jacobian_determinant(Jac);
			value += dJ * weights(i);
		}

		return value;
	}


	int number() const
	{
		return m_number();
	}


	std::string type()
	{
		std::string type;
		switch (NVT) {
		case 4:
			type = "Quadrangle4";
			break;
		case 8:
			type = "Quadrangle8";
			break;
		case 9:
			type = "Quadrangle9";
			break;
		case 12:
			type = "Quadrangle12";
			break;
		case 16:
			type = "Quadrangle16";
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
		}
		return type;
	}


	unsigned int dimension() const
	{
		return 2;
	}


	std::size_t vertices_number() const
	{
		return this->m_vertex.size();
	}


	unsigned int edges_number() const
	{
		return 4;
	}


	unsigned int faces_number() const
	{
		return 1;
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

		// vector of global vertices coordinates
		auto Coord = this->vertices_coordinates();

		// Jacobian matrix
		konam_mat Jacobian = prod(Nder, Coord);

		return Jacobian;
	}


	double Jacobian_determinant()
	{
		return this->calculate_Jacobian_determinant(this->Jacobian_matrix());
	}


	konam_mat shape_functions_derivatives_matrix()
	{
		// number of integration points
		auto const num_int_pts = this->integration_points_number();

		// Gauss-Legendre quadrature -> abscissa
		auto abscissa = std::get<0>(quadrangle_gauss_legendre_integration_points(num_int_pts));

		// matrix of shape function derivatives with respect to local coordinates
		konam_mat Nder(this->dimension(), this->vertices_number(), 0.0);

		for (unsigned int i = 0; i < num_int_pts; ++i)
			Nder = quadrangle_shape_functions_derivatives<NVT>(abscissa, i);

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


	double calculate_Jacobian_determinant(const konam_mat& Jac)
	{
		// The determinant of the Jacobian matrix |J| is used for the transformation
		// of integrals from the global coordinate system to the local coordinate system.

		double dJ = std::pow(Jac(0, 0) * Jac(1, 1) - Jac(0, 1) * Jac(1, 0), 2) +
			std::pow(Jac(0, 2) * Jac(1, 0) - Jac(0, 0) * Jac(1, 2), 2) +
			std::pow(Jac(0, 1) * Jac(1, 2) - Jac(0, 2) * Jac(1, 1), 2);

		return std::sqrt(dJ);
	}


	inline int exact_quadrature()
	{
		int value{};

		switch (NVT) {
		case 4:
			value = 4;
			break;
		case 8:
		case 9:
			value = 9;
			break;
		case 12:
			value = 16;	// preveri
			break;
		case 16:
			value = 16;	// preveri
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
		case 4:
			value = 1;
			break;
		case 8:
		case 9:
			value = 4;
			break;
		case 12:
			value = 9;	// preveri
			break;
		case 16:
			value = 9;	// preveri
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file " __FILE__);
		}
		return value;
	}

};


#endif // !QUADRANGLE_H