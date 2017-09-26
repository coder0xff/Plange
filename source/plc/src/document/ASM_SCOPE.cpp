// This file was generated using Parlex's cpp_generator

#include "ASM_STATEMENT.hpp"
#include "IC.hpp"
#include "ASM_SCOPE.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<ASM_SCOPE> ASM_SCOPE::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<ASM_SCOPE_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<ASM_SCOPE>(value.value());
	}
	return std::optional<ASM_SCOPE>();
}

} // namespace plc
