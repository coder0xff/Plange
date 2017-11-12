// This file was generated using Parlex's cpp_generator

#include "INHERITANCE_LIST.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "INHERITANCE_ITEM_PREFIX.hpp"

plc::INHERITANCE_LIST::field_2_t_1_t plc::INHERITANCE_LIST::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<erased<INHERITANCE_ITEM_PREFIX>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

plc::INHERITANCE_LIST plc::INHERITANCE_LIST::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().INHERITANCE_LIST.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::optional<erased<INHERITANCE_ITEM_PREFIX>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<field_2_t_1_t>>::build(&*children[2], w);
	return INHERITANCE_LIST(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::INHERITANCE_LIST::recognizer() {
	return plange_grammar::get().INHERITANCE_LIST.get_recognizer();
}
