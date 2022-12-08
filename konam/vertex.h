#ifndef VERTEX_H
#define VERTEX_H


#include <string>
#include <stdexcept>
#include <map>
#include <memory>
#include "konam_array.h"
//#include "global_system_definition.h"


using namespace std::string_literals;


class Vertex
{
public:

	Vertex(unsigned int number, double xCoord, double yCoord, double zCoord)
		: m_number{ number }, m_x_coord{ xCoord }, m_y_coord{ yCoord }, m_z_coord{ zCoord }
	{
		if (m_number > 999999)
			throw std::out_of_range("Invalid vertex number. Error in file " __FILE__);

		auto vertex = ms_vertex_map.insert(std::make_pair(m_number, std::make_unique<Vertex>(*this)));
		if (!vertex.second) {
			const std::string error = "Vertex number "s + std::to_string(m_number) + " already exist.";
			throw std::invalid_argument(error);
		}
	}

	//Vertex(unsigned int number, double xCoord, double yCoord)
	//	: m_number{ number }, m_x_coord{ xCoord }, m_y_coord{ yCoord }, m_z_coord{ 0.0 }
	//{
	//	if (m_number > 999999)
	//		throw std::out_of_range("Invalid vertex number. Error in file " __FILE__);

	//	auto vertex = ms_vertex_map.insert(std::make_pair(m_number, std::make_unique<Vertex>(*this)));
	//	if (!vertex.second) {
	//		const std::string error = "Vertex number "s + std::to_string(m_number) + " already exist.";
	//		throw std::invalid_argument(error);
	//	}
	//}

   
	unsigned int number() const
	{
		return this->m_number;
	}


	double coordinate(const int coord) const
	{
		switch (coord) {
		case 1:     // x-coordinate
			return this->m_x_coord;
		case 2:     // y-coordinate
			return this->m_y_coord;
		case 3:     // z-coordinate
			return this->m_z_coord;
		default:    // invalid coordinate
			throw std::invalid_argument("Invalid coordinate. Error in file " __FILE__);
		}
	}


	double x_coord() const
	{
		return this->m_x_coord;
	}


	double y_coord() const
	{
		return this->m_y_coord;
	}


	double z_coord() const
	{
		return this->m_z_coord;
	}


	static inline auto vertex_coordinates(int vertex)
	{
		konam_vec coord(3);
		coord(0) = ms_vertex_map[vertex]->x_coord();
		coord(1) = ms_vertex_map[vertex]->y_coord();
		coord(2) = ms_vertex_map[vertex]->z_coord();

		return coord;
	}


	void set_coord(double x, double y, double z)
	{
		this->m_x_coord = x;
		this->m_y_coord = y;
		this->m_z_coord = z;
	}


	void set_Id(unsigned int num)	// preveri!
	{
		auto check = check_if_Id_exists(num);

		if (check) {
			auto new_key = ms_vertex_map.extract(num);
			new_key.key() = num;
			ms_vertex_map.insert(std::move(new_key));
		}
		else {
			ms_vertex_map.insert(std::move(num));
		}
		//this->m_number = num;	// preveri, če obstaja ter vstavi v map 
	}


private:

    unsigned int m_number;
    double m_x_coord, m_y_coord, m_z_coord;
	static inline std::map<unsigned int, std::unique_ptr<Vertex>> ms_vertex_map;


	bool check_if_Id_exists(unsigned int key)
	{
		if (auto it = ms_vertex_map.find(key); it == ms_vertex_map.end())
			return false;

		return true;
	}

};


#endif // !VERTEX_H