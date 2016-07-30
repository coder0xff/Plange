#include <string>
#include <iostream>

void emit_warning(int warnNumber, std::string description, std::string const & file, int const line, std::string const & info) {
	std::string errNumberString = std::to_string(warnNumber);
	errNumberString = std::string(4 - errNumberString.length(), '0') + errNumberString;
	std::string message = "Warning W" + errNumberString + " " + description + " " + file + ":" + std::to_string(line) + " " + info + "\n";
	std::cerr << message;
}
