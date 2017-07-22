#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "parlex/details/recognizer.hpp"

namespace parlex {
namespace details {

class job;
class token;

class terminal : public recognizer {
public:
	virtual ~terminal() = default;

	virtual bool test(std::u32string const & document, size_t documentPosition) const = 0;
	size_t const length;
	bool is_terminal() const final { return true; }
protected:
	terminal(std::string id, size_t length);
};

} // namespace details
} // namespace parlex

#endif //TERMINAL_HPP
