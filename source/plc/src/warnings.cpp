#include <iostream>
#include <string>

namespace plc {

void emit_warning(int const warnNumber, std::string const& description, std::string const& file, int const line, std::string const& info) {
	auto errNumberString = std::to_string(warnNumber);
	errNumberString = std::string(4 - errNumberString.length(), '0') + errNumberString;
	auto const message = "Warning W" + errNumberString + " " + description + " " + file + ":" + std::to_string(line) + " " + info + "\n";
	std::cerr << message;
}

}
