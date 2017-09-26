// This file was generated using Parlex's cpp_generator

#include "NON_ZERO_DECIMAL_DIGIT.hpp"
#include "NON_NEG_INTEGER.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<NON_NEG_INTEGER> NON_NEG_INTEGER::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<NON_NEG_INTEGER_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<NON_NEG_INTEGER>(value.value());
	}
	return std::optional<NON_NEG_INTEGER>();
}

} // namespace plc
