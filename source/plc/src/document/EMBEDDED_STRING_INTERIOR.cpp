// This file was generated using Parlex's cpp_generator

#include "EMBEDDED_STRING_INTERIOR.hpp"
#include "PAYLOAD.hpp"
#include "EMBEDDED_STRING_INTERIOR.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<EMBEDDED_STRING_INTERIOR> EMBEDDED_STRING_INTERIOR::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<EMBEDDED_STRING_INTERIOR_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<EMBEDDED_STRING_INTERIOR>(value.value());
	}
	return std::optional<EMBEDDED_STRING_INTERIOR>();
}

} // namespace plc
