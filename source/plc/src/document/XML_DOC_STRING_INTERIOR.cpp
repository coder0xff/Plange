// This file was generated using Parlex's cpp_generator

#include "PAYLOAD.hpp"
#include "XML_DOC_STRING_INTERIOR.hpp"
#include "XML_DOC_STRING_INTERIOR.hpp"
#include "plange_grammar.hpp"

namespace plc {

std::optional<XML_DOC_STRING_INTERIOR> XML_DOC_STRING_INTERIOR::build(std::vector<parlex::details::match>::iterator & i) {
	std::optional<XML_DOC_STRING_INTERIOR_base> value;
	parlex::details::behavior::build(value, i);
	if (value.has_value()) {
		return std::make_optional<XML_DOC_STRING_INTERIOR>(value.value());
	}
	return std::optional<XML_DOC_STRING_INTERIOR>();
}

} // namespace plc
