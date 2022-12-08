#ifndef TRUSS_CONTAINER_H
#define TRUSS_CONTAINER_H


#include <map>
#include <memory>
#include <string>
#include <stdexcept>


using namespace std::string_literals;


class Truss_Container
{
public:

	Truss_Container() = delete;


	template<typename T>
	static inline void insert_element(unsigned int number, T& elem)
	{
		//static_assert(T == Truss_2n || T == Truss_3n || T == Truss_4n || T == Truss_5n,
		//	"Invalid element type. Valid types are Truss_2n, Truss_3n, Truss_4n and Truss_5n.");

		//auto pr = ms_element_map.insert(std::make_pair(number, std::make_unique<T>(elem)));
		//if (!pr.second) {
		//	const std::string error = "Truss number "s + std::to_string(number) + " already exist.";
		//	throw std::invalid_argument(error);
		//}
	}


private:

	template<typename T>
	static inline std::map<unsigned int, std::unique_ptr<T>> ms_element_map;

};


#endif // !TRUSS_CONTAINER_H
