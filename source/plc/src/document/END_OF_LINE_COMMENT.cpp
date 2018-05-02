// This file was generated using Parlex's cpp_generator

#include "END_OF_LINE_COMMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::END_OF_LINE_COMMENT plc::END_OF_LINE_COMMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F0x2F_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::not_newline_t>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x0A_t>>::build(&*children[2], w);
	return END_OF_LINE_COMMENT(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::END_OF_LINE_COMMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().END_OF_LINE_COMMENT));
	return result;
}
