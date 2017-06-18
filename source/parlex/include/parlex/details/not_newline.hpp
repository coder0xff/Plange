#ifndef NOT_NEWLINE_HPP
#define NOT_NEWLINE_HPP

#include "parlex/terminal.hpp"

namespace parlex {
namespace details {

class not_newline_t : public terminal {
public:
	not_newline_t();
	~not_newline_t() override = default;
	bool test(std::u32string const & document, size_t documentPosition) const override final;
};

} // namespace details
} // namespace parlex

#endif //NOT_NEWLINE_HPP
