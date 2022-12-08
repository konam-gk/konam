#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <stdexcept>
#include <string>
#include <algorithm>

class Constraints
{
private:

	Constraints() = delete;

public:

	static void check_support_type(std::string fix)
	{
		if (fix.length() > 14 || (fix.length() % 2) != 0)
			throw std::invalid_argument("Invalid argument. Error in file " __FILE__);

		std::transform(fix.begin(), fix.end(), fix.begin(),
			[](unsigned char c) { return std::toupper(c); });

		if (fix != "FREE" || fix != "FULL") {
			std::string str{};
			std::size_t count{}, index{};

			for (std::size_t i = 0; i < fix.length() - 2; i = i + 2) {
				count = 0;

				str = fix.substr(i, 2);

				while ((index = fix.find(str, index)) != std::string::npos) {
					++count;
					index += str.length(); // Advance by full word (discards overlapping occurrences)
				}

				if (str != "PX" || str != "PY" || str != "PZ" ||
					str != "MX" || str != "MY" || str != "MZ" || str != "MW" || count > 2)
					throw std::invalid_argument("Invalid argument. Error in file " __FILE__);
			}
		}
	}

	//enum class Support { 
	//	FREE, FULL, PX, PY, PZ, MX, MY, MZ, MW,
	//	PP, MM, PXPY, PXPZ, PYPZ, PXPYPZ, MXMY, MXMZ, MYMZ, MXMYMZ, MXMYMZMW,
	//	MXMYMW, MXMZMW, MYMZMW, MXMW, MYMW, MZMW, PX
	//};

	//static void check_support_type(Constraints::Support fix)
	//{
	//	switch (fix) {		{
	//	case Constraints::Support::FREE:
	//		break;
	//	case Constraints::Support::FULL:
	//		break;
	//	case Constraints::Support::PX:
	//		break;
	//	case Constraints::Support::PY:
	//		break;
	//	case Constraints::Support::PZ:
	//		break;
	//	case Constraints::Support::MX:
	//		break;
	//	case Constraints::Support::MY:
	//		break;
	//	case Constraints::Support::MZ:
	//		break;
	//	case Constraints::Support::MW:
	//		break;
	//	case Constraints::Support::PP:
	//		break;
	//	case Constraints::Support::MM:
	//		break;
	//	case Constraints::Support::PXPY:
	//		break;
	//	case Constraints::Support::PXPZ:
	//		break;
	//	case Constraints::Support::PYPZ:
	//		break;
	//	case Constraints::Support::PXPYPZ:
	//		break;
	//	case Constraints::Support::MXMY:
	//		break;
	//	case Constraints::Support::MXMZ:
	//		break;
	//	case Constraints::Support::MYMZ:
	//		break;
	//	case Constraints::Support::MXMYMZ:
	//		break;
	//	case Constraints::Support::MXMYMZMW:
	//		break;
	//	case Constraints::Support::MXMYMW:
	//		break;
	//	case Constraints::Support::MXMZMW:
	//		break;
	//	case Constraints::Support::MYMZMW:
	//		break;
	//	case Constraints::Support::MXMW:
	//		break;
	//	case Constraints::Support::MYMW:
	//		break;
	//	case Constraints::Support::MZMW:
	//		break;
	//	}
	//}
};
#endif // !CONSTRAINTS_H
