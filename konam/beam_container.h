#ifndef BEAM_CONTAINER_H
#define BEAM_CONTAINER_H


#include <map>
#include <memory>
#include <string>
#include <stdexcept>


using namespace std::string_literals;


class Beam_Container
{
public:

	Beam_Container() = delete;


	template<typename T>
	static inline void insert_element(unsigned int number, T& elem)
	{
		//static_assert(T == Beam_2n || T == Beam_3n || T == Beam_4n || T == Beam_5n,
			//"Invalid element type. Valid types are Beam_2n, Beam_3n, Beam_4n and Beam_5n.");

		auto pr = ms_element_map.insert(std::make_pair(number, std::make_unique<T>(elem)));
		if (!pr.second) {
			const std::string error = "Beam number "s + std::to_string(number) + " already exist.";
			throw std::invalid_argument(error);
		}
	}


private:

	template<typename T>
	static inline std::map<unsigned int, std::unique_ptr<T>> ms_element_map;

};


#endif // !BEAM_CONTAINER_H
