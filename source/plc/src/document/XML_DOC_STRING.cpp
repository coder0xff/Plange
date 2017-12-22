// This file was generated using Parlex's cpp_generator

#include "XML_DOC_STRING.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "XML_DOC_STRING_INTERIOR.hpp"

plc::XML_DOC_STRING plc::XML_DOC_STRING::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().XML_DOC_STRING.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x600x600x60_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<XML_DOC_STRING_INTERIOR>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x600x600x60_t>>::build(&*children[2], w);
	return XML_DOC_STRING(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::XML_DOC_STRING::recognizer() {
	return plange_grammar::get().XML_DOC_STRING.get_recognizer();
}
