// This file was generated using Parlex's cpp_generator

#include "LESSER_CHAIN_LOOP.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "LESSER_CHAIN_LOOP.hpp"

plc::LESSER_CHAIN_LOOP::field_4_t_1_t plc::LESSER_CHAIN_LOOP::field_4_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<LESSER_CHAIN_LOOP>>::build(&*children[1], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1));
}

plc::LESSER_CHAIN_LOOP plc::LESSER_CHAIN_LOOP::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().LESSER_CHAIN_LOOP.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0x3D_t>,
		parlex::details::document::text<literal_0x3C_t>,
		parlex::details::document::text<literal_0x3D0x3C_t>,
		parlex::details::document::text<literal_0xE20x890xA4_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(&*children[3], w);
	return LESSER_CHAIN_LOOP(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::details::recognizer const & plc::LESSER_CHAIN_LOOP::recognizer() {
	return plange_grammar::get().LESSER_CHAIN_LOOP.get_recognizer();
}
