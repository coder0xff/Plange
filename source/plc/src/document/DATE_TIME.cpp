// This file was generated using Parlex's cpp_generator

#include "DATE_TIME.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "DATE.hpp"
#include "TIME.hpp"

plc::DATE_TIME plc::DATE_TIME::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<DATE>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_T_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<TIME>>::build(&*children[2], w);
	return DATE_TIME(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::DATE_TIME::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DATE_TIME));
	return result;
}
