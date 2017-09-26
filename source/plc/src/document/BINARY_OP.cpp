// This file was generated using Parlex's cpp_generator

#include "BINARY_ARITHMETIC_OP.hpp"
#include "BINARY_COLLECTION_OP.hpp"
#include "BINARY_LOGICAL_OP.hpp"
#include "BITWISE_OP.hpp"
#include "CONSTRUCTIVE_OP.hpp"
#include "RELATIONAL_OP.hpp"
#include "BINARY_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<BINARY_OP> BINARY_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<BINARY_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<BINARY_OP>(value.value());
	}
	return std::optional<BINARY_OP>();
}

} // namespace plc
