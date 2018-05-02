// This file was generated using Parlex's cpp_generator

#include "XML_DOC_STRING_INTERIOR.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "PAYLOAD.hpp"
#include "XML_DOC_STRING_INTERIOR.hpp"

#include "XML_DOC_STRING_INTERIOR.hpp"

namespace plc {

XML_DOC_STRING_INTERIOR XML_DOC_STRING_INTERIOR::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return XML_DOC_STRING_INTERIOR(parlex::detail::document::element<XML_DOC_STRING_INTERIOR_base>::build(b, w));
}

} // namespace plc
plc::XML_DOC_STRING_INTERIOR_1_t plc::XML_DOC_STRING_INTERIOR_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x60_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<XML_DOC_STRING_INTERIOR>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x60_t>>::build(&*children[2], w);
	return XML_DOC_STRING_INTERIOR_1_t(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::XML_DOC_STRING_INTERIOR::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().XML_DOC_STRING_INTERIOR));
	return result;
}
