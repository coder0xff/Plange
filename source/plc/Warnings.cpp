#include <string>
#include <iostream>

void emit_warning(int warnNumber, std::string description, std::string info) {
	std::string errNumberString = std::to_string(warnNumber);
	errNumberString = std::string(4 - errNumberString.length(), '0') + errNumberString;
	std::string message = "Warning W" + errNumberString + " " + description + " " + info + "\n";
	std::cerr << message;
	throw std::exception(message.c_str());
}
