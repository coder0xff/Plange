// This file was generated using Parlex's cpp_generator

#include "BIT_AND.hpp"
#include "BIT_OR.hpp"
#include "BIT_XOR.hpp"
#include "BITWISE_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<BITWISE_OP> BITWISE_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<BITWISE_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<BITWISE_OP>(value.value());
	}
	return std::optional<BITWISE_OP>();
}

} // namespace plc
