#ifndef STRING_TERMINAL_HPP
#define STRING_TERMINAL_HPP

#include "parlex/terminal.hpp"
#include "utils.hpp"

namespace parlex {
namespace details {

class string_terminal : public terminal {
public:
	string_terminal(std::u32string const & s) : terminal(to_utf8(s), s.length()), s(s) {}
	virtual ~string_terminal() = default;
	bool test(std::u32string const & document, size_t documentPosition) const override final {
		return document.compare(documentPosition, length, s) == 0;
	}
	std::u32string get_content() const {
		return s;
	}
private:
	std::u32string const s;
};

} //namespace details
} //namespace parlex

#endif
