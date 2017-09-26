// This file was generated using Parlex's cpp_generator

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "IMPLICIT_TYPE_DEREFERENCE.hpp"
#include "TYPE_DEREFERENCE.hpp"
#include "PARAMETER_NATURAL.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<PARAMETER_NATURAL> PARAMETER_NATURAL::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<PARAMETER_NATURAL_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<PARAMETER_NATURAL>(value.value());
	}
	return std::optional<PARAMETER_NATURAL>();
}

} // namespace plc
