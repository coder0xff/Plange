// This file was generated using Parlex's cpp_generator

#include "BOOL.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<BOOL> BOOL::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<BOOL_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<BOOL>(value.value());
	}
	return std::optional<BOOL>();
}

} // namespace plc
