// This file was generated using Parlex's cpp_generator

#include "SUBSET_CHAIN_LOOP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "SUBSET_CHAIN_LOOP.hpp"

plc::SUBSET_CHAIN_LOOP::field_4_t_1_t plc::SUBSET_CHAIN_LOOP::field_4_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<SUBSET_CHAIN_LOOP>>::build(&*children[1], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1));
}

plc::SUBSET_CHAIN_LOOP plc::SUBSET_CHAIN_LOOP::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().SUBSET_CHAIN_LOOP.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0xE20x8A0x86_t>,
		parlex::detail::document::text<literal_subs_t>,
		parlex::detail::document::text<literal_0xE20x8A0x82_t>,
		parlex::detail::document::text<literal_psubs_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::optional<field_4_t_1_t>>::build(&*children[3], w);
	return SUBSET_CHAIN_LOOP(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::detail::recognizer const & plc::SUBSET_CHAIN_LOOP::recognizer() {
	return plange_grammar::get().SUBSET_CHAIN_LOOP.get_recognizer();
}
