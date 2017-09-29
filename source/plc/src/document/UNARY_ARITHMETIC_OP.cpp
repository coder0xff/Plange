// This file was generated using Parlex's cpp_generator

#include "FACTORIAL.hpp"
#include "NEGATION.hpp"
#include "POST_DEC.hpp"
#include "POST_INC.hpp"
#include "PRE_DEC.hpp"
#include "PRE_INC.hpp"
#include "RADICAL.hpp"
#include "UNARY_ARITHMETIC_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<UNARY_ARITHMETIC_OP> UNARY_ARITHMETIC_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<UNARY_ARITHMETIC_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<UNARY_ARITHMETIC_OP>(value.value());
	}
	return std::optional<UNARY_ARITHMETIC_OP>();
}

} // namespace plc
