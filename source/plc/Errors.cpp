#include <string>
#include <iostream>

void emit_error(int errNumber, std::string description, std::string info) {
	std::string errNumberString = std::to_string(errNumber);
	errNumberString = std::string(4 - errNumberString.length(), '0') + errNumberString;
	std::string message = "Error E" + errNumberString + " " + description + " " + info + "\n";
	std::cerr << message;
	throw std::exception(message.c_str());
}