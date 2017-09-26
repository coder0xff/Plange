// This file was generated using Parlex's cpp_generator

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "RANGE.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<RANGE> RANGE::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<RANGE_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<RANGE>(value.value());
	}
	return std::optional<RANGE>();
}

} // namespace plc
