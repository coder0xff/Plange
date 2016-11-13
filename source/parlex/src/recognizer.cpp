#include "parlex/recognizer.hpp"

namespace parlex {

recognizer::recognizer(std::string const& id) : id(id) {}

bool recognizer::is_terminal() const { return false; }

}