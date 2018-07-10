#ifndef INCLUDED_PARLEX_NOT_NEWLINE_HPP
#define INCLUDED_PARLEX_NOT_NEWLINE_HPP

#include "parlex/detail/terminal.hpp"

namespace parlex {
namespace detail {

class not_newline_t : public terminal {
public:
	not_newline_t();
	~not_newline_t() override = default;
	bool test(std::u32string const & document, uint32_t documentPosition) const override final;
};

} // namespace detail
} // namespace parlex

#endif // INCLUDED_PARLEX_NOT_NEWLINE_HPP
