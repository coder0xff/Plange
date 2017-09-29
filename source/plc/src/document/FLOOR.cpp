// This file was generated using Parlex's cpp_generator

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "FLOOR.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<FLOOR> FLOOR::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<FLOOR_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<FLOOR>(value.value());
	}
	return std::optional<FLOOR>();
}

} // namespace plc
