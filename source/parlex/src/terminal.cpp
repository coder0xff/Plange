#include "parlex/terminal.hpp"

namespace parlex {

terminal::terminal(std::string id) : recognizer(id) {}

bool terminal::is_terminal() const
{
	return true;
}

}