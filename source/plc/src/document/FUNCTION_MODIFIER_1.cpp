// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_2.hpp"
#include "FUNCTION_MODIFIER_THROWING.hpp"
#include "FUNCTION_MODIFIER_1.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<FUNCTION_MODIFIER_1> FUNCTION_MODIFIER_1::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<FUNCTION_MODIFIER_1_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<FUNCTION_MODIFIER_1>(value.value());
	}
	return std::optional<FUNCTION_MODIFIER_1>();
}

} // namespace plc
