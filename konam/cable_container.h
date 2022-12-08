#ifndef CABLE_CONTAINER_H
#define CABLE_CONTAINER_H


#include <map>
#include <memory>
#include <string>
#include <stdexcept>


using namespace std::string_literals;


class Cable_Container
{
public:

	Cable_Container() = delete;


	template<typename T>
	static inline void insert_element(unsigned int number, T& elem)
	{
		static_assert(T == Cable_2n || T == Cable_3n || T == Cable_4n || T == Cable_5n,
			"Invalid element type. Valid types are Cable_2n, Cable_3n, Cable_4n and Cable_5n.");

		auto pr = ms_element_map.insert(std::make_pair(number, std::make_unique<T>(elem)));
		if (!pr.second) {
			const std::string error = "Cable number "s + std::to_string(number) + " already exist.";
			throw std::invalid_argument(error);
		}
	}


private:

	template<typename T>
	static inline std::map<unsigned int, std::unique_ptr<T>> ms_element_map;

};


#endif // !CABLE_CONTAINER_H
