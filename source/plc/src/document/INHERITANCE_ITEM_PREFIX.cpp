// This file was generated using Parlex's cpp_generator

#include "INHERITANCE_ITEM_PREFIX.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ICR.hpp"
#include "VISIBILITY_MODIFIER.hpp"

plc::INHERITANCE_ITEM_PREFIX::field_1_t_2_t plc::INHERITANCE_ITEM_PREFIX::field_1_t_2_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<ICR>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_diamond_t>>::build(&*children[2], w);
	return field_1_t_2_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::INHERITANCE_ITEM_PREFIX plc::INHERITANCE_ITEM_PREFIX::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().INHERITANCE_ITEM_PREFIX.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::variant<
		erased<VISIBILITY_MODIFIER>,
		field_1_t_2_t,
		parlex::detail::document::text<literal_diamond_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<ICR>>::build(&*children[1], w);
	return INHERITANCE_ITEM_PREFIX(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::INHERITANCE_ITEM_PREFIX::recognizer() {
	return plange_grammar::get().INHERITANCE_ITEM_PREFIX.get_recognizer();
}
