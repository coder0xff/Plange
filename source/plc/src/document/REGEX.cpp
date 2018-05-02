// This file was generated using Parlex's cpp_generator

#include "REGEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::REGEX plc::REGEX::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_R_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<void>>::build(&*children[1], w);
	return REGEX(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::REGEX::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().REGEX));
	return result;
}
