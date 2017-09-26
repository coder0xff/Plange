// This file was generated using Parlex's cpp_generator

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "CEILING.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<CEILING> CEILING::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<CEILING_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<CEILING>(value.value());
	}
	return std::optional<CEILING>();
}

} // namespace plc
