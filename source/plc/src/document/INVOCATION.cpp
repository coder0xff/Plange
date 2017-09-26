// This file was generated using Parlex's cpp_generator

#include "ARRAY_INVOCATION.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "TYPE_INVOCATION.hpp"
#include "INVOCATION.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<INVOCATION> INVOCATION::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<INVOCATION_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<INVOCATION>(value.value());
	}
	return std::optional<INVOCATION>();
}

} // namespace plc
