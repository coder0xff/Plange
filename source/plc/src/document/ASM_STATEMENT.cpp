// This file was generated using Parlex's cpp_generator

#include "ASM_STATEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASM_EXPRESSION.hpp"
#include "ASM_OP.hpp"
#include "IC.hpp"
#include "ICR.hpp"

plc::ASM_STATEMENT::field_2_t_1_t::field_3_t_1_t::field_2_t_1_t plc::ASM_STATEMENT::field_2_t_1_t::field_3_t_1_t::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<ASM_EXPRESSION>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASM_STATEMENT::field_2_t_1_t::field_3_t_1_t plc::ASM_STATEMENT::field_2_t_1_t::field_3_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ASM_STATEMENT::field_2_t_1_t plc::ASM_STATEMENT::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<ICR>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<ASM_EXPRESSION>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<field_3_t_1_t>>::build(&*children[2], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::ASM_STATEMENT plc::ASM_STATEMENT::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_STATEMENT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<ASM_OP>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<parlex::details::document::text<literal_0x0A_t>>::build(&*children[3], w);
	return ASM_STATEMENT(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}


parlex::details::recognizer const & plc::ASM_STATEMENT::recognizer() {
	return plange_grammar::get().ASM_STATEMENT.get_recognizer();
}
