// This file was generated using Parlex's cpp_generator

#include "VISIBILITY_MODIFIER.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<VISIBILITY_MODIFIER> VISIBILITY_MODIFIER::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<VISIBILITY_MODIFIER_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<VISIBILITY_MODIFIER>(value.value());
	}
	return std::optional<VISIBILITY_MODIFIER>();
}

} // namespace plc
