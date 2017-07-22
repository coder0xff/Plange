#include "parlex/details/terminal.hpp"

#include <stdexcept>

namespace parlex {
namespace details {

terminal::terminal(std::string id, size_t length) : recognizer(id), length(length) { if (!length) { throw std::invalid_argument("length"); } }

} // namespace details
} // namespace parlex
