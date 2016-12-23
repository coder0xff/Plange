#ifndef NOT_DOUBLE_QUOTE_HPP
#define NOT_DOUBLE_QUOTE_HPP

#include "parlex/terminal.hpp"

namespace parlex {
namespace details {

class not_double_quote_t : public terminal {
public:
	not_double_quote_t();
	virtual ~not_double_quote_t() = default;
	bool test(std::u32string const & document, size_t documentPosition) const override final;
	size_t get_length() const override final;
};

}

namespace builtins {

extern details::not_double_quote_t not_double_quote;

}
}

#endif
