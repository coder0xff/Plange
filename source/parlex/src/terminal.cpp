#include "parlex/terminal.hpp"

namespace parlex {

terminal::terminal(std::string id, size_t length) : recognizer(id), length(length) { if (!length) { throw std::invalid_argument("length"); } }

}
