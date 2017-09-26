// This file was generated using Parlex's cpp_generator

#include "CROSS_PRODUCT.hpp"
#include "DOT_PRODUCT.hpp"
#include "MULTIPLICATION.hpp"
#include "MULTIPLICATIVE_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<MULTIPLICATIVE_OP> MULTIPLICATIVE_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<MULTIPLICATIVE_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<MULTIPLICATIVE_OP>(value.value());
	}
	return std::optional<MULTIPLICATIVE_OP>();
}

} // namespace plc
