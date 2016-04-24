#include <sstream>

#include "parlex/details/utils.hpp"

std::string escape_for_dot(std::string s) {
	std::ostringstream result;
	result << "\"";
	for (char c : s) {
		switch (c) {
		case '"':
			result << "\\\"";
			break;
		case '\\':
			result << "\\\\";
			break;
		default:
			result << c;
		}
	}
	result << "\"";
	return result.str();
}