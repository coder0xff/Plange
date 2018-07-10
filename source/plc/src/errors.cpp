#include <iostream>
#include <string>

namespace plc {

void emit_error(int const errNumber, std::string const& description, std::string const& file, int const line, std::string const& info) {
	auto errNumberString = std::to_string(errNumber);
	errNumberString = std::string(4 - errNumberString.length(), '0') + errNumberString;
	auto message = "Error E" + errNumberString + " " + description + " " + file + ":" + std::to_string(line) + " " + info + "\n";
	std::cerr << message;
	throw std::logic_error(message.c_str());
}

}
