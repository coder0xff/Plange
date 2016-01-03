#include <string>
#include <sstream>

#include "parlex/details/uni_trunc.hpp"

//quick & dirty
std::string uni_trunc(std::u32string const & s) {
	std::stringstream result;
	for (char32_t const & c : s) {
		if ((int)c < 0x100) {
			result << (char)(int)c;
		} else {
			result << "?";
		}
	}
	return result.str();
}

