// This file was generated using Parlex's cpp_generator

#include "ASM_IDENTIFIER.hpp"
#include "ASM_PTR_ARITHMETIC_ATT.hpp"
#include "ASM_PTR_ARITHMETIC_INTEL.hpp"
#include "NON_FRACTIONAL.hpp"
#include "ASM_EXPRESSION.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<ASM_EXPRESSION> ASM_EXPRESSION::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<ASM_EXPRESSION_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<ASM_EXPRESSION>(value.value());
	}
	return std::optional<ASM_EXPRESSION>();
}

} // namespace plc
