// This file was generated using Parlex's cpp_generator

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "NEAREST_INTEGER.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<NEAREST_INTEGER> NEAREST_INTEGER::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<NEAREST_INTEGER_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<NEAREST_INTEGER>(value.value());
	}
	return std::optional<NEAREST_INTEGER>();
}

} // namespace plc
