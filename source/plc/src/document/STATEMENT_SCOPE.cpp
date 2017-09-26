// This file was generated using Parlex's cpp_generator

#include "IC.hpp"
#include "STATEMENT.hpp"
#include "STATEMENT_SCOPE.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<STATEMENT_SCOPE> STATEMENT_SCOPE::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<STATEMENT_SCOPE_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<STATEMENT_SCOPE>(value.value());
	}
	return std::optional<STATEMENT_SCOPE>();
}

} // namespace plc
