#include "parlex/detail/terminal.hpp"

#include <stdexcept>

namespace parlex {
namespace detail {

terminal::terminal(std::string id, size_t length) : recognizer(id), length(length) { if (!length) { throw std::invalid_argument("length"); } }

} // namespace detail
} // namespace parlex
