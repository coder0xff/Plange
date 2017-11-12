// This file was generated using Parlex's cpp_generator

#include "SUBSET_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "SUBSET_CHAIN_LOOP.hpp"

plc::SUBSET_CHAIN plc::SUBSET_CHAIN::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().SUBSET_CHAIN.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<SUBSET_CHAIN_LOOP>>::build(&*children[2], w);
	return SUBSET_CHAIN(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::SUBSET_CHAIN::recognizer() {
	return plange_grammar::get().SUBSET_CHAIN.get_recognizer();
}
