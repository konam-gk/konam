#ifndef SLINE_CONTAINER_H
#define SLINE_CONTAINER_H


#include <map>
#include <memory>
#include <string>
#include <stdexcept>


using namespace std::string_literals;


class SLine;


class SLine_Container
{
public:

	SLine_Container() = delete;


	static inline void insert_line(unsigned int number, SLine& line)
	{
		auto pr = ms_sline_map.insert(std::make_pair(number, std::make_unique<SLine>(line)));
		if (!pr.second) {
			const std::string error = "Structural-Line number "s + std::to_string(number) + " already exist.";
			throw std::invalid_argument(error);
		}
	}


private:

	static inline std::map<unsigned int, std::unique_ptr<SLine>> ms_sline_map;

};


#endif // !SLINE_CONTAINER_H
