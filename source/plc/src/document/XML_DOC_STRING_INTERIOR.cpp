// This file was generated using Parlex's cpp_generator

#include "XML_DOC_STRING_INTERIOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "PAYLOAD.hpp"
#include "XML_DOC_STRING_INTERIOR.hpp"
#include "XML_DOC_STRING_INTERIOR.hpp"

namespace plc {

XML_DOC_STRING_INTERIOR XML_DOC_STRING_INTERIOR::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	return XML_DOC_STRING_INTERIOR(parlex::details::document::element<XML_DOC_STRING_INTERIOR_base>::build(b, n));
}

} // namespace plc
plc::XML_DOC_STRING_INTERIOR_2_t plc::XML_DOC_STRING_INTERIOR_2_t::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return XML_DOC_STRING_INTERIOR_2_t(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0])
);
}

