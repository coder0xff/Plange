// This file was generated using Parlex's cpp_generator

#include "EXPRESSION.hpp"
#include "ARGUMENT.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<ARGUMENT> ARGUMENT::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<ARGUMENT_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<ARGUMENT>(value.value());
	}
	return std::optional<ARGUMENT>();
}

} // namespace plc
