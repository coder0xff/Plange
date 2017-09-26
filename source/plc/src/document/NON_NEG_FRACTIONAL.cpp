// This file was generated using Parlex's cpp_generator

#include "NON_NEG_FRACTIONAL.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<NON_NEG_FRACTIONAL> NON_NEG_FRACTIONAL::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<NON_NEG_FRACTIONAL_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<NON_NEG_FRACTIONAL>(value.value());
	}
	return std::optional<NON_NEG_FRACTIONAL>();
}

} // namespace plc
