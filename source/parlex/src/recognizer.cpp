#include "parlex/recognizer.hpp"

#include <functional>

#include "utils.hpp"

namespace parlex {

recognizer::recognizer(std::string const& id) : id(id) {}

bool recognizer::is_terminal() const { return false; }

std::ostream& operator<<(std::ostream& os, const recognizer & r) { return os << r.id; }

}
