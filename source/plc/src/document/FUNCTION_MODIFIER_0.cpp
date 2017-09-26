// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_1.hpp"
#include "FUNCTION_MODIFIER_STABILITY.hpp"
#include "FUNCTION_MODIFIER_0.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<FUNCTION_MODIFIER_0> FUNCTION_MODIFIER_0::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<FUNCTION_MODIFIER_0_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<FUNCTION_MODIFIER_0>(value.value());
	}
	return std::optional<FUNCTION_MODIFIER_0>();
}

} // namespace plc
