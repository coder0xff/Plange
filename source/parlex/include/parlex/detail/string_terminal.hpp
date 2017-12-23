#ifndef STRING_TERMINAL_HPP
#define STRING_TERMINAL_HPP

#include "parlex/detail/terminal.hpp"

namespace parlex {
namespace detail {

class string_terminal : public terminal {
public:
	explicit string_terminal(std::u32string const & s);

	~string_terminal() override = default;

	bool test(std::u32string const & document, size_t documentPosition) const override final;

	std::u32string get_content() const;

private:
	std::u32string const s;
};

} //namespace detail
} //namespace parlex

#endif //STRING_TERMINAL_HPP
