#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <string>
#include <iostream>
#include <sstream>


#define DEBUG(...) logging::debug_impl(__VA_ARGS__)

namespace logging {

void print_endl(std::string s) {
	std::cout << s << std::endl;
}

template<typename... Ts>
std::string stringify(Ts... parameters);

template<typename T, typename... Us>
std::string stringify(T head, Us... tail) {
	std::stringstream ss;
	ss << head;
	ss << stringify(tail...);
	return ss.str();
}

template<>
std::string stringify() {
	return std::string();
}

template<typename... Ts>
void debug_impl(Ts... args) {
	print_endl(stringify(args...));
}

}

#endif
