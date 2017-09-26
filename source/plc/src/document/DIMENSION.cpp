// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_ANALYSIS_OP.hpp"
#include "IDENTIFIER.hpp"
#include "DIMENSION.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<DIMENSION> DIMENSION::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<DIMENSION_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<DIMENSION>(value.value());
	}
	return std::optional<DIMENSION>();
}

} // namespace plc
