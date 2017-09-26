// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_CALLING_CONVENTION.hpp"
#include "FUNCTION_MODIFIER_MODEL.hpp"
#include "FUNCTION_MODIFIER_4.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<FUNCTION_MODIFIER_4> FUNCTION_MODIFIER_4::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<FUNCTION_MODIFIER_4_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<FUNCTION_MODIFIER_4>(value.value());
	}
	return std::optional<FUNCTION_MODIFIER_4>();
}

} // namespace plc
