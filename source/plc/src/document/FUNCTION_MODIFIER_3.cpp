// This file was generated using Parlex's cpp_generator

#include "FUNCTION_MODIFIER_4.hpp"
#include "FUNCTION_MODIFIER_PLATFORM.hpp"
#include "FUNCTION_MODIFIER_3.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<FUNCTION_MODIFIER_3> FUNCTION_MODIFIER_3::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<FUNCTION_MODIFIER_3_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<FUNCTION_MODIFIER_3>(value.value());
	}
	return std::optional<FUNCTION_MODIFIER_3>();
}

} // namespace plc
