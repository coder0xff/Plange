#ifndef INCLUDED_PARLEX_TERMINAL_HPP
#define INCLUDED_PARLEX_TERMINAL_HPP

#include "parlex/detail/recognizer.hpp"

namespace parlex {
namespace detail {

class job;
class token;

class terminal : public recognizer {
public:
	virtual ~terminal() = default;

	virtual bool test(std::u32string const & document, uint32_t documentPosition) const = 0;
	uint32_t const length;
	bool is_terminal() const final { return true; }
protected:
	terminal(std::string const & id, uint32_t length);
};

} // namespace detail
} // namespace parlex

#endif // INCLUDED_PARLEX_TERMINAL_HPP
