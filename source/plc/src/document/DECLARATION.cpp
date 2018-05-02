// This file was generated using Parlex's cpp_generator

#include "DECLARATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "XML_DOC_STRING.hpp"

plc::DECLARATION::field_1_t_1_t plc::DECLARATION::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<XML_DOC_STRING>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::DECLARATION plc::DECLARATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	return DECLARATION(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::DECLARATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DECLARATION));
	return result;
}
