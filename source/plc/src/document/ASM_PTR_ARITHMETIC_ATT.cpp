// This file was generated using Parlex's cpp_generator

#include "ASM_IDENTIFIER.hpp"
#include "ASM_PTR_ARITHMETIC_ATT_REG.hpp"
#include "NON_FRACTIONAL.hpp"
#include "ASM_PTR_ARITHMETIC_ATT.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<ASM_PTR_ARITHMETIC_ATT> ASM_PTR_ARITHMETIC_ATT::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<ASM_PTR_ARITHMETIC_ATT_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<ASM_PTR_ARITHMETIC_ATT>(value.value());
	}
	return std::optional<ASM_PTR_ARITHMETIC_ATT>();
}

} // namespace plc
