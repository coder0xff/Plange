// This file was generated using Parlex's cpp_generator

#include "ALLOCATION.hpp"
#include "CARDINALITY.hpp"
#include "KLEENE_STAR.hpp"
#include "UNARY_ARITHMETIC_OP.hpp"
#include "UNARY_LOGICAL_OP.hpp"
#include "UNARY_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<UNARY_OP> UNARY_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<UNARY_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<UNARY_OP>(value.value());
	}
	return std::optional<UNARY_OP>();
}

} // namespace plc
