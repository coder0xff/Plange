// This file was generated using Parlex's cpp_generator

#include "EQUALITY_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EQUALITY_CHAIN_LOOP.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::EQUALITY_CHAIN plc::EQUALITY_CHAIN::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().EQUALITY_CHAIN.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	auto v_2 = parlex::details::document::element<erased<EQUALITY_CHAIN_LOOP>>::build(document, *children[2], w);
	return EQUALITY_CHAIN(std::move(v_0), std::move(v_1), std::move(v_2));
}

