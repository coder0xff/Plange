// This file was generated using Parlex's cpp_generator

#include "SUBSET_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "SUBSET_CHAIN_LOOP.hpp"

plc::SUBSET_CHAIN plc::SUBSET_CHAIN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<SUBSET_CHAIN_LOOP>>::build(&*children[2], w);
	return SUBSET_CHAIN(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::SUBSET_CHAIN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUBSET_CHAIN));
	return result;
}
