// This file was generated using Parlex's cpp_generator

#include "EQUALITY_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EQUALITY_CHAIN_LOOP.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::EQUALITY_CHAIN plc::EQUALITY_CHAIN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EQUALITY_CHAIN_LOOP>>::build(&*children[2], w);
	return EQUALITY_CHAIN(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::EQUALITY_CHAIN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EQUALITY_CHAIN));
	return result;
}
