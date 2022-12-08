#ifndef GLOBAL_SYSTEM_DEFINITION_H
#define GLOBAL_SYSTEM_DEFINITION_H


#include <string>
#include <algorithm>
#include <cassert>
#include "line_gauss_legendre_integration_points.h"
#include "line_gauss_lobatto_integration_points.h"
#include "triangle_gauss_legendre_integration_points.h"
#include "quadrangle_gauss_legendre_integration_points.h"
#include "hexahedron_gauss_legendre_integration_points.h"


class GSDefinition
{
private:

	GSDefinition()
	{
		this->m_type = "3D";
		this->m_gravity_direction = "NEGZ";
		this->m_integration_method = 1;
	}

	std::string m_type;
	std::string m_gravity_direction;
	static unsigned int m_number_of_dimensions;
	static unsigned int m_integration_method;	// 1 = Gauss-Lobatto (default), 2 = Gauss-Legendre


public:

	enum class System { _3D, _2D, _2DSS, _2DSN, _2DPL };
	enum class GDir { POSX, POSY, POSZ, NEGX, NEGY, NEGZ };


	void set_system(GSDefinition::System system)
	{
		switch (system) {
		case System::_3D:	// spatial structures
			this->m_type = "3D";
			this->m_number_of_dimensions = 3;
			break;
		case System::_2D:	// plane frame or pannel
			assert(gDir == GSDefinition::GDir::POSX || gDir == GSDefinition::GDir::NEGX ||
				gDir == GSDefinition::GDir::POSY || gDir == GSDefinition::GDir::NEGY);
			this->m_type = "2D";
			this->m_number_of_dimensions = 2;
			break;
		case System::_2DSS:	// plane stress
			assert(gDir == GSDefinition::GDir::POSX || gDir == GSDefinition::GDir::NEGX ||
				gDir == GSDefinition::GDir::POSY || gDir == GSDefinition::GDir::NEGY);
			this->m_type = "2DSS";
			this->m_number_of_dimensions = 2;
			break;
		case System::_2DSN:	// plane strain
			assert(gDir == GSDefinition::GDir::POSX || gDir == GSDefinition::GDir::NEGX ||
				gDir == GSDefinition::GDir::POSY || gDir == GSDefinition::GDir::NEGY);
			this->m_type = "2DSN";
			this->m_number_of_dimensions = 2;
			break;
		case System::_2DPL:	// plane girder or plate bending
			assert(gDir == GSDefinition::GDir::POSZ || gDir == GSDefinition::GDir::NEGZ);
			this->m_type = "2DPL";
			this->m_number_of_dimensions = 2;
			break;
		default:
			throw std::invalid_argument("Invalid argument. Error in file " __FILE__);
		}
	}


	void set_gravity_direction(GSDefinition::GDir gDir)
	{
		switch (gDir) {
		case GDir::POSX:
			this->m_gravity_direction = "POSX";
			break;
		case GDir::POSY:
			this->m_gravity_direction = "POSY";
			break;
		case GDir::POSZ:
			this->m_gravity_direction = "POSZ";
			break;
		case GDir::NEGX:
			this->m_gravity_direction = "NEGX";
			break;
		case GDir::NEGY:
			this->m_gravity_direction = "NEGY";
			break;
		case GDir::NEGZ:
			this->m_gravity_direction = "NEGZ";
			break;
		default:
			throw std::invalid_argument("Invalid argument. Error in file " __FILE__);
		}
	}


	void set_integration_method(unsigned int& intMethod)
	{
		switch (intMethod) {
		case 1:		// Gauss-Lobatto (default)
			m_integration_method = 1;
			break;
		case 2:		// Gauss-Legendre
			m_integration_method = 2;
			break;
		default:
			throw std::invalid_argument("Invalid argument. Error in file " __FILE__);
		}
	}


	static auto get_integration_method()
	{
		return m_integration_method;
	}


	static auto get_number_of_dimensions()
	{
		return m_number_of_dimensions;
	}


	auto get_gravity_direction() const
	{
		return this->m_gravity_direction;
	}


	auto get_type() const
	{
		return this->m_type;
	}


	static auto line_integration_points(const int num_int_pts)
	{
		konam_mat coordinates(num_int_pts, 1);
		konam_vec weights(num_int_pts);

		if (get_integration_method() == 1)
			std::make_pair(coordinates, weights) = line_gauss_lobatto_integration_points(num_int_pts);
		else if (get_integration_method() == 2)
			std::make_pair(coordinates, weights) = line_gauss_legendre_integration_points(num_int_pts);

		return std::make_pair(coordinates, weights);
	}


	static auto triangle_integration_points(const int num_int_pts)
	{
		konam_mat coordinates(num_int_pts, 2);
		konam_vec weights(num_int_pts);

		std::make_pair(coordinates, weights) = triangle_gauss_legendre_integration_points(num_int_pts);

		return std::make_pair(coordinates, weights);
	}


	static auto quadrangle_integration_points(const int num_int_pts)
	{
		konam_mat coordinates(num_int_pts, 2);
		konam_vec weights(num_int_pts);

		std::make_pair(coordinates, weights) = quadrangle_gauss_legendre_integration_points(num_int_pts);

		return std::make_pair(coordinates, weights);
	}


	static auto hexahedron_integration_points(const int num_int_pts)
	{
		konam_mat coordinates(num_int_pts, 3);
		konam_vec weights(num_int_pts);

		std::make_pair(coordinates, weights) = hexahedron_gauss_legendre_integration_points(num_int_pts);

		return std::make_pair(coordinates, weights);
	}

};
#endif // !GLOBAL_SYSTEM_DEFINITION_H
