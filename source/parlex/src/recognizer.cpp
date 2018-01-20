#include "parlex/detail/recognizer.hpp"

#include <functional>

#include "utils.hpp"

namespace parlex {
namespace detail {

recognizer::recognizer(std::string const & name) : name(name) {
}

bool recognizer::is_terminal() const { return false; }

std::ostream& operator<<(std::ostream & os, const recognizer & r) { return os << r.name; }

} // namespace detail
} // namespace parlex
