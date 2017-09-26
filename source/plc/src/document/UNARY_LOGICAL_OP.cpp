// This file was generated using Parlex's cpp_generator

#include "ALL.hpp"
#include "EXISTS.hpp"
#include "EXISTS_ONE.hpp"
#include "NOT.hpp"
#include "UNARY_LOGICAL_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<UNARY_LOGICAL_OP> UNARY_LOGICAL_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<UNARY_LOGICAL_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<UNARY_LOGICAL_OP>(value.value());
	}
	return std::optional<UNARY_LOGICAL_OP>();
}

} // namespace plc
