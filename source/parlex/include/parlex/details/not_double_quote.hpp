#ifndef NOT_DOUBLE_QUOTE_HPP
#define NOT_DOUBLE_QUOTE_HPP

#include "parlex/terminal.hpp"

namespace parlex {
namespace details {

class not_double_quote_t : public terminal {
public:
	not_double_quote_t();
	~not_double_quote_t() override = default;
	bool test(std::u32string const & document, size_t documentPosition) const override final;
};

} // namespace details
} // namespace parlex

#endif //NOT_DOUBLE_QUOTE_HPP
