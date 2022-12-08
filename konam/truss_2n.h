#ifndef TRUSS_2N_H
#define TRUSS_2N_H


#include "truss_container.h"
#include "cross_section.h"
#include "material.h"
#include "spoint.h"
#include "sline.h"
#include "line.h"


class Truss_2n
{
public:

	//Truss_2n(unsigned int number, SPoint& n1, SPoint& n2, unsigned int sectionNumber)
	//	: m_line{ std::make_shared<Line<2>>(number, n1, n2) }, m_cross_section_number{ sectionNumber }
	//{
	//	Truss_Container::insert_element(number, *this);
	//}


	Truss_2n(unsigned int number, SPoint& n1, SPoint& n2, unsigned int sectionNumber, double prestress = 0.0)
		//: m_line{ std::make_shared<Line<2>>(number, n1, n2) }, m_cross_section_number{ sectionNumber },
		//m_prestress_force{ prestress }
	{
		//Truss_Container::insert_element(number, *this);	// error
	}


	Truss_2n(unsigned int number, Vertex& n1, Vertex& n2, SLine& sline, double prestress = 0.0)
		//: m_line{ std::make_shared<Line<2>>(number, n1, n2) },
		//m_cross_section_number{ std::make_shared<SLine>(sline)->cross_section_at_start() },
		//m_prestress_force{ prestress }
	{
		//Truss_Container::insert_element(number, *this);
	}


	konam_mat stiffness_matrix()
	{
		// Number of element nodes
		const int elnod = 2;

		// Number of itegration points
		const auto intMethod = GSDefinition::integration_method();
		const unsigned int num_int_pts = this->m_line->integration_points_number();
				
		// Numerical integration
		auto [abscissa, weights] = this->m_line->numerical_integration(num_int_pts);

		// Constitutive value
		const int crossSectionNumber = this->cross_section_number();
		const int materialNumber = this->material_number();
		double Em = Material::elastic_modulus(materialNumber);
		double A = Cross_Section::area(crossSectionNumber);
		double Dmat = Em * A;

		// matrix of shape function derivatives
		konam_mat Nder;

		// Jacobian matrix
		konam_mat Jacobian;

		// matrix of points coordinates
		konam_mat Coord = this->nodes_coordinates();

		// Strain Matrix - Bmat
		konam_mat Bmat;

		// stiffness matrix of element
		konam_mat Ke(elnod, elnod, 0.0);

		for (unsigned int i = 0; i < num_int_pts; ++i) {
			Nder = line_shape_functions_derivatives<elnod>(abscissa, i);

			Jacobian = prod(Nder, Coord);

			double jac_norm{};
			for (unsigned int i = 0; i < Jacobian.size1(); ++i)
				for (unsigned int j = 0; j < Jacobian.size2(); ++j)
					jac_norm += Jacobian(i, j) * Jacobian(i, j);
				
			Bmat = Nder / std::sqrt(jac_norm);
			konam_mat BD = trans(Bmat) * Dmat;
			konam_mat BDB = prod(BD, Bmat);
			konam_mat BDBJ = BDB * std::sqrt(jac_norm);

			Ke += BDBJ * weights(i);
		}

		return Ke;
	}


	inline int number() const
	{
		return this->m_line->number();
	}


	inline int cross_section_number() const
	{
		return this->m_cross_section_number;
	}


	inline int material_number() const
	{
		return Cross_Section::material_number(this->cross_section_number());
	}
	

	// Element length
	double length()
	{
		return this->m_line->length();
	}


	inline int start_node() const
	{
		return this->m_line->get_vertex_ptr(0)->number();
	}


	inline int end_node() const
	{
		return this->m_line->get_vertex_ptr(1)->number();
	}


	konam_mat nodes_coordinates()
	{
		return this->m_line->vertices_coordinates();
	}


	inline double prestress_force() const
	{
		return this->m_prestress_force;
	}


	double set_prestress_force(double force)
	{
		this->m_prestress_force = force;
	}


private:

	std::shared_ptr<Line<2>> m_line;
	double m_prestress_force;
	unsigned int m_cross_section_number;

};


#endif // !TRUSS_2N_H