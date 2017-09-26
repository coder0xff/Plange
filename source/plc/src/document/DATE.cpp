// This file was generated using Parlex's cpp_generator

#include "DATE_YEAR_DAY.hpp"
#include "DATE_YEAR_MONTH_DAY.hpp"
#include "DATE.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<DATE> DATE::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<DATE_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<DATE>(value.value());
	}
	return std::optional<DATE>();
}

} // namespace plc
