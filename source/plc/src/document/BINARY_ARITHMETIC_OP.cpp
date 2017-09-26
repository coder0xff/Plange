// This file was generated using Parlex's cpp_generator

#include "ADDITION.hpp"
#include "ADD_SUB.hpp"
#include "DIVISION.hpp"
#include "EXPONENTIATION.hpp"
#include "INTEGER_DIVISION.hpp"
#include "MODULATION.hpp"
#include "MULTIPLICATIVE_OP.hpp"
#include "SHIFTL.hpp"
#include "SHIFTR.hpp"
#include "SUBTRACTION.hpp"
#include "BINARY_ARITHMETIC_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<BINARY_ARITHMETIC_OP> BINARY_ARITHMETIC_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<BINARY_ARITHMETIC_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<BINARY_ARITHMETIC_OP>(value.value());
	}
	return std::optional<BINARY_ARITHMETIC_OP>();
}

} // namespace plc
