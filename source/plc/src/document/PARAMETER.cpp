// This file was generated using Parlex's cpp_generator

#include "PARAMETER_ANALYTIC.hpp"
#include "PARAMETER_NATURAL.hpp"
#include "PARAMETER.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<PARAMETER> PARAMETER::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<PARAMETER_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<PARAMETER>(value.value());
	}
	return std::optional<PARAMETER>();
}

} // namespace plc
