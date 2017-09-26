// This file was generated using Parlex's cpp_generator

#include "AND.hpp"
#include "IFF.hpp"
#include "IMPLICATION.hpp"
#include "MAPS_TO.hpp"
#include "NAND.hpp"
#include "NOR.hpp"
#include "OR.hpp"
#include "XOR.hpp"
#include "BINARY_LOGICAL_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<BINARY_LOGICAL_OP> BINARY_LOGICAL_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<BINARY_LOGICAL_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<BINARY_LOGICAL_OP>(value.value());
	}
	return std::optional<BINARY_LOGICAL_OP>();
}

} // namespace plc
