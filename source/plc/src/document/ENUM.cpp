// This file was generated using Parlex's cpp_generator

#include "ENUM.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ENUM_ELEMENT.hpp"
#include "IC.hpp"
#include "INHERITANCE_LIST.hpp"

plc::ENUM::field_2_t_1_t plc::ENUM::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_inheriting_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::ENUM::field_3_t_1_t plc::ENUM::field_3_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_implementing_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::ENUM::field_4_t_1_t::field_1_t_1_t plc::ENUM::field_4_t_1_t::field_1_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x3B_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<erased<ENUM_ELEMENT>>::build(&*children[3], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::ENUM::field_4_t_1_t plc::ENUM::field_4_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<ENUM_ELEMENT>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<field_1_t_1_t>>::build(&*children[1], w);
	return field_4_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ENUM plc::ENUM::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ENUM.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_enum_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_3_t_1_t>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<std::optional<field_4_t_1_t>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<parlex::details::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return ENUM(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}


parlex::details::recognizer const & plc::ENUM::recognizer() {
	return plange_grammar::get().ENUM.get_recognizer();
}
