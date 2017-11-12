// This file was generated using Parlex's cpp_generator

#include "LIST.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::LIST::elements_t_1_t::field_2_t_1_t plc::LIST::elements_t_1_t::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x2C0x20_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::LIST::elements_t_1_t plc::LIST::elements_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_2_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	return elements_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::LIST plc::LIST::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().LIST.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x5B0x7C_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<elements_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<parlex::details::document::text<literal_0x7C0x5D_t>>::build(&*children[3], w);
	return LIST(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::details::recognizer const & plc::LIST::recognizer() {
	return plange_grammar::get().LIST.get_recognizer();
}
