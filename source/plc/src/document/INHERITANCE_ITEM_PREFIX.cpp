// This file was generated using Parlex's cpp_generator

#include "INHERITANCE_ITEM_PREFIX.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ICR.hpp"
#include "VISIBILITY_MODIFIER.hpp"

plc::INHERITANCE_ITEM_PREFIX::field_1_t_2_t plc::INHERITANCE_ITEM_PREFIX::field_1_t_2_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<ICR>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<literal_diamond_t>>::build(&*children[2], w);
	return field_1_t_2_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::INHERITANCE_ITEM_PREFIX plc::INHERITANCE_ITEM_PREFIX::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().INHERITANCE_ITEM_PREFIX.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		erased<VISIBILITY_MODIFIER>,
		field_1_t_2_t,
		parlex::details::document::text<literal_diamond_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<ICR>>::build(&*children[1], w);
	return INHERITANCE_ITEM_PREFIX(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::INHERITANCE_ITEM_PREFIX::recognizer() {
	return plange_grammar::get().INHERITANCE_ITEM_PREFIX.get_recognizer();
}
