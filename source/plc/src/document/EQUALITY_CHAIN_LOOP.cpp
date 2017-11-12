// This file was generated using Parlex's cpp_generator

#include "EQUALITY_CHAIN_LOOP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EQUALITY_CHAIN_LOOP.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::EQUALITY_CHAIN_LOOP::field_2_t_1_t plc::EQUALITY_CHAIN_LOOP::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<EQUALITY_CHAIN_LOOP>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::EQUALITY_CHAIN_LOOP plc::EQUALITY_CHAIN_LOOP::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().EQUALITY_CHAIN_LOOP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x3D_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[3], w);
	return EQUALITY_CHAIN_LOOP(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::details::recognizer const & plc::EQUALITY_CHAIN_LOOP::recognizer() {
	return plange_grammar::get().EQUALITY_CHAIN_LOOP.get_recognizer();
}
