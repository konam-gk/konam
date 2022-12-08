#ifndef LINE_H
#define LINE_H

//#include "line_gauss_legendre_integration_points.h"
#include "line_shape_functions.h"
#include "line_shape_functions_derivatives.h"
#include "vertex.h"
#include "global_system_definition.h"


/*
 *    Line2 (linear)
 *
 *   0-----------1
 *
 *
 *    Line3 (quadratic)
 *
 *   0-----2-----1
 *
 *
 *    Line4 (cubic)
 *
 *   0---2---3---1
 *
 *
 *    Line5 (quartic)
 *
 *   0--2--3--4--1
 *
 */



template<unsigned int NVT = 2>
// NVT - number of element vertices
class Line
{
public:
	
	static_assert(NVT == 2 || NVT == 3 || NVT == 4 || NVT == 5, "Invalid number of element vertices. "
		"Valid numbers are 2, 3, 4 and 5.");


	// Constructors
	template<typename... T,
		typename = std::enable_if_t<std::conjunction_v<std::is_same<Vertex, T>...> && sizeof...(T) == NVT>>
		Line(unsigned int number, const T&...vertex)
		: m_number{ number }, m_vertex{ std::make_shared<Vertex>(vertex)... }
	{
	}


	template<typename T,
		typename = std::enable_if_t<std::is_same_v<std::vector<Vertex>, T>>>
		Line(unsigned int number, const T& vertices) : m_number{ number }
	{
		assert(vertices.size() == NVT);

		for (const auto& i : vertices)
			m_vertex.push_back(std::make_shared<Vertex>(i));
	}


	// Element length
	constexpr double length()
	//double length() //const
	{
		auto coord = this->vertices_coordinates();
		double value{};
		const auto vnum = this->vertices_number();

		double temp{};	// temporary variable
		for (unsigned int i = 1; i < vnum; ++i) {
			temp = 0.0;
			for (unsigned int j = 0; j < GSDefinition::get_number_of_dimensions(); ++j)
				temp += std::pow(coord(i, j) - coord(i - 1, j), 2);
			value += std::sqrt(temp);
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
		case 2:
			type = "Line2";
			break;
		case 3:
			type = "Line3";
			break;
		case 4:
			type = "Line4";
			break;
		case 5:
			type = "Line5";
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file: " __FILE__);
		}
		return type;
	}


	unsigned int dimension() const
	{
		return 1;
	}


	std::size_t vertices_number() const
	{
		return this->m_vertex.size();
	}


	unsigned int edges_number() const
	{
		return NVT - 1;
	}


	std::shared_ptr<Vertex> get_vertex_ptr(int num) const
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
		auto Jac = this->Jacobian_matrix();
		double dJ{};

		for (unsigned int i = 0; i < Jac.cols(); ++i)
			dJ += std::pow(Jac(0, i), 2);

		return dJ;
	}


	auto numerical_integration(const int num_int_pts)
	{
		//return GSDefinition::integration_points(GSDefinition::Element::Line, num_int_pts);
		return GSDefinition::line_integration_points(num_int_pts);
	}


	konam_mat shape_functions_derivatives_matrix()
	{
		// number of integration points
		auto const num_int_pts = this->integration_points_number();

		// Numerical integration
		//auto abscissa = std::get<0>(line_gauss_legendre_integration_points(num_int_pts));
		//auto abscissa = std::get<0>(GSDefinition::integration_points(GSDefinition::Element::Line, num_int_pts));
		auto abscissa = std::get<0>(this->numerical_integration(num_int_pts));

		// matrix of shape function derivatives - Nder
		konam_mat Nder(this->dimension(), this->vertices_number(), 0.0);

		for (unsigned int i = 0; i < num_int_pts; ++i)
			Nder = line_shape_functions_derivatives<NVT>(abscissa, i);

		return Nder;
	}


	konam_mat vertices_coordinates()
	{
		const auto vnum = this->vertices_number();
		konam_mat coord(vnum, GSDefinition::number_of_dimensions());

		for (unsigned int i = 0; i < vnum; ++i)
			for (unsigned int j = 0; j < GSDefinition::get_number_of_dimensions(); ++j)
				coord(i, j) = this->m_vertex[i]->coordinate(j + 1);

		return coord;
	}


	//inline int vertex(unsigned int num) const
	//{
	//	// if...
	//	return this->m_vertex[num]->number();
	//}


private:

	std::vector<std::shared_ptr<Vertex>> m_vertex;
	unsigned int m_number;


	// returns a number of integration points
	inline int exact_quadrature()
	{
		int value{};

		switch (NVT) {
		case 2:
			value = 1;
			break;
		case 3:
			value = 2;
			break;
		case 4:
			value = 3;
			break;
		case 5:
			value = 4;
			break;
		default:
			throw std::invalid_argument("Invalid number of element vertices. Error if file: " __FILE__);
		}
		return value;
	}

};


#endif // !LINE_H