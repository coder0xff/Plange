#include <string>
#include <sstream>

#include "parlex/details/unicode.hpp"

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

std::u32string uni_grow(std::string const & s) {
#ifdef _MSC_VER
	std::u32string result;
	for (char const & c : s) {
		if ((int)c < 0x80) {
			result = result + (char32_t)c;
		}
		else {
			result += (char32_t)'?';
		}
	}
	return result;
#else
	std::basic_stringstream<char32_t> result;
	for (char const & c : s) {
		if ((int)c < 0x80) {
			result << (char32_t)(int)c;
		}
		else {
			result << (char32_t)(int)'?';
		}
	}
	return result.str();
#endif
}
