// This file was generated using Parlex's cpp_generator

#include "COMMENT.hpp"
#include "EMBEDDED_COMMENT.hpp"
#include "END_OF_LINE_COMMENT.hpp"
#include "WS.hpp"
#include "IC.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<IC> IC::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<IC_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<IC>(value.value());
	}
	return std::optional<IC>();
}

} // namespace plc
