// This file was generated using Parlex's cpp_generator

#include "COMPOSITION.hpp"
#include "COMPOUND.hpp"
#include "NULL_COALESCE.hpp"
#include "PREPEND.hpp"
#include "CONSTRUCTIVE_OP.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<CONSTRUCTIVE_OP> CONSTRUCTIVE_OP::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<CONSTRUCTIVE_OP_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<CONSTRUCTIVE_OP>(value.value());
	}
	return std::optional<CONSTRUCTIVE_OP>();
}

} // namespace plc
