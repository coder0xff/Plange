// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INVOCATION_HPP
#define INCLUDED_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ARRAY_INVOCATION;
struct PARENTHETICAL_INVOCATION;
struct TYPE_INVOCATION;

typedef std::variant<
	erased<PARENTHETICAL_INVOCATION>,
	erased<ARRAY_INVOCATION>,
	erased<TYPE_INVOCATION>
> INVOCATION_base;

struct INVOCATION: INVOCATION_base {
	static std::optional<INVOCATION> build(std::vector<parlex::details::match>::iterator & i);
	explicit INVOCATION(INVOCATION_base const & value) : INVOCATION_base(value) {}
};
} // namespace plc



#endif //INCLUDED_INVOCATION_HPP
