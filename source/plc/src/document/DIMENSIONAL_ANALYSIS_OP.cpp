// This file was generated using Parlex's cpp_generator

#include "UNIT_DIVISION.hpp"
#include "UNIT_EXPONENTIATION.hpp"
#include "UNIT_MULTIPLICATION.hpp"
#include "DIMENSIONAL_ANALYSIS_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<DIMENSIONAL_ANALYSIS_OP> DIMENSIONAL_ANALYSIS_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<DIMENSIONAL_ANALYSIS_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<DIMENSIONAL_ANALYSIS_OP>(value.value());
	}
	return std::optional<DIMENSIONAL_ANALYSIS_OP>();
}

} // namespace plc
