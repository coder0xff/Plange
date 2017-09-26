// This file was generated using Parlex's cpp_generator

#include "NON_ZERO_DECIMAL_DIGIT.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<NON_ZERO_DECIMAL_DIGIT> NON_ZERO_DECIMAL_DIGIT::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<NON_ZERO_DECIMAL_DIGIT_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<NON_ZERO_DECIMAL_DIGIT>(value.value());
	}
	return std::optional<NON_ZERO_DECIMAL_DIGIT>();
}

} // namespace plc
