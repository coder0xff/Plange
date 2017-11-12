// This file was generated using Parlex's cpp_generator

#include "XML_DOC_STRING_INTERIOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "XML_DOC_STRING_INTERIOR.hpp"

#include "XML_DOC_STRING_INTERIOR.hpp"

namespace plc {

XML_DOC_STRING_INTERIOR XML_DOC_STRING_INTERIOR::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().XML_DOC_STRING_INTERIOR.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return XML_DOC_STRING_INTERIOR(parlex::details::document::element<XML_DOC_STRING_INTERIOR_base>::build(b, w));
}

} // namespace plc
plc::XML_DOC_STRING_INTERIOR_1_t plc::XML_DOC_STRING_INTERIOR_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x60_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<XML_DOC_STRING_INTERIOR>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<literal_0x60_t>>::build(&*children[2], w);
	return XML_DOC_STRING_INTERIOR_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::XML_DOC_STRING_INTERIOR::recognizer() {
	return plange_grammar::get().XML_DOC_STRING_INTERIOR.get_recognizer();
}
