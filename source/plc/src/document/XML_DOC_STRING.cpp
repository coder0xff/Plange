// This file was generated using Parlex's cpp_generator

#include "XML_DOC_STRING.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "XML_DOC_STRING_INTERIOR.hpp"

plc::XML_DOC_STRING plc::XML_DOC_STRING::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x600x600x60_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<XML_DOC_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x600x600x60_t>>::build(&*children[2], w);
	return XML_DOC_STRING(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::XML_DOC_STRING::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().XML_DOC_STRING));
	return result;
}
