#ifndef NODE_H
#define NODE_H


#include <string>
#include <stdexcept>
#include <map>
#include <memory>
#include "konam_array.h"
#include "vertex.h"


using namespace std::string_literals;


class Node //: public Vertex
{
public:

	Node(unsigned int number, double xCoord, double yCoord, double zCoord)
		: m_vertex{ std::make_shared<Vertex>(number, xCoord, yCoord, zCoord) }
	{
	}


	Node(unsigned int number, double xCoord, double yCoord)
		: m_vertex{ std::make_shared<Vertex>(number, xCoord, yCoord, 0.0) }
	{
	}


	unsigned int number() const
	{
		return this->m_vertex->number();
	}


	double coordinate(const int coord) const
	{
		switch (coord) {
		case 1:     // x-coordinate
			return this->m_vertex->x_coord();
		case 2:     // y-coordinate
			return this->m_vertex->y_coord();
		case 3:     // z-coordinate
			return this->m_vertex->z_coord();
		default:    // invalid coordinate
			throw std::invalid_argument("Invalid coordinate. Error in file " __FILE__);
		}
	}


	double x_coord() const
	{
		return this->m_vertex->x_coord();
	}


	double y_coord() const
	{
		return this->m_vertex->y_coord();
	}


	double z_coord() const
	{
		return this->m_vertex->x_coord();
	}


	static inline auto node_coordinates(int node)
	{
		konam_vec coord(3);
		coord(0) = ms_node_map[node]->x_coord();
		coord(1) = ms_node_map[node]->y_coord();
		coord(2) = ms_node_map[node]->z_coord();

		return coord;
	}


private:

	std::shared_ptr<Vertex> m_vertex;
	static inline std::map<unsigned int, std::unique_ptr<Node>> ms_node_map;

};


#endif // !NODE_H