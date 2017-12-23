#include "parlex/detail/terminal.hpp"

#include <stdexcept>

namespace parlex {
namespace detail {

terminal::terminal(std::string const id, size_t const length) : recognizer(id), length(length) { if (!length) { throw std::invalid_argument("length"); } }

} // namespace detail
} // namespace parlex
