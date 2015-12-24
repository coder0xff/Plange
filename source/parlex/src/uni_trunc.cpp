#include <string>
#include <sstream>

#include "uni_trunc.hpp"

//quick & dirty
std::string uni_trunc(std::u32string const & s) {
	std::stringstream result;
	for (char32_t const & c : s) {
		if ((int32_t)c < 0x100) {
			result << (char)(int32_t)c;
		} else {
			result << "?";
		}
	}
	return result.str();
}

