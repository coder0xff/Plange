#ifndef NOT_DOUBLE_QUOTE_HPP
#define NOT_DOUBLE_QUOTE_HPP

#include "parlex/terminal.hpp"

namespace parlex {
namespace details {

class not_double_quote_t : public terminal {
public:
	virtual ~not_double_quote_t() = default;
	virtual bool test(std::u32string const & document, size_t documentPosition) const final;
	virtual size_t get_length() const final;
	virtual std::string get_id() const final;
};

}

namespace builtins {

extern details::not_double_quote_t not_double_quote;

}
}

#endif
