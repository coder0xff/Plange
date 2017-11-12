// This file was generated using Parlex's cpp_generator

#include "THIS.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::THIS::field_1_t_1_t plc::THIS::field_1_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<parlex::details::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}

plc::THIS plc::THIS::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().THIS.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_this_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(&*children[1], w);
	return THIS(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::THIS::recognizer() {
	return plange_grammar::get().THIS.get_recognizer();
}
