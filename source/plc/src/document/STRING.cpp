// This file was generated using Parlex's cpp_generator

#include "STRING.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<STRING> STRING::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<STRING_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<STRING>(value.value());
	}
	return std::optional<STRING>();
}

} // namespace plc
