// This file was generated using Parlex's cpp_generator

#include "FUNCTION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "BLOCK.hpp"
#include "FUNCTION_MODIFIER_0.hpp"
#include "IC.hpp"
#include "PARAMETER.hpp"

plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::field_1_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<erased<PARAMETER>>::build(&*children[3], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::FUNCTION::field_1_t_1_t::field_2_t_1_t plc::FUNCTION::field_1_t_1_t::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<PARAMETER>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_1_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2));
}

plc::FUNCTION::field_1_t_1_t plc::FUNCTION::field_1_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<parlex::details::document::text<literal_0x29_t>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}

plc::FUNCTION::field_2_t_1_t plc::FUNCTION::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<FUNCTION_MODIFIER_0>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1));
}

plc::FUNCTION plc::FUNCTION::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().FUNCTION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<BLOCK>>::build(&*children[2], w);
	return FUNCTION(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::FUNCTION::recognizer() {
	return plange_grammar::get().FUNCTION.get_recognizer();
}
