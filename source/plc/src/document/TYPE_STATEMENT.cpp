// This file was generated using Parlex's cpp_generator

#include "IC.hpp"
#include "STATEMENT.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT.hpp"
#include "VISIBILITY_MODIFIER.hpp"
#include "TYPE_STATEMENT.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<TYPE_STATEMENT> TYPE_STATEMENT::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<TYPE_STATEMENT_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<TYPE_STATEMENT>(value.value());
	}
	return std::optional<TYPE_STATEMENT>();
}

} // namespace plc
