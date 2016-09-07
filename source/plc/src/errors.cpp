#include <string>
#include <iostream>

void emit_error(int errNumber, std::string const & description, std::string const & file, int const line, std::string const & info) {
	std::string errNumberString = std::to_string(errNumber);
	errNumberString = std::string(4 - errNumberString.length(), '0') + errNumberString;
	std::string message = "Error E" + errNumberString + " " + description + " " + file + ":" + std::to_string(line) + " " + info + "\n";
	std::cerr << message;
	throw std::logic_error(message.c_str());
}
