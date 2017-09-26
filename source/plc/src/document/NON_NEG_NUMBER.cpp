// This file was generated using Parlex's cpp_generator

#include "NON_NEG_FRACTIONAL.hpp"
#include "NON_NEG_NON_FRACTIONAL.hpp"
#include "NON_NEG_NUMBER.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<NON_NEG_NUMBER> NON_NEG_NUMBER::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<NON_NEG_NUMBER_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<NON_NEG_NUMBER>(value.value());
	}
	return std::optional<NON_NEG_NUMBER>();
}

} // namespace plc
