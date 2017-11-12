// This file was generated using Parlex's cpp_generator

#include "TYPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "INHERITANCE_LIST.hpp"
#include "TYPE_SCOPE.hpp"

plc::TYPE::field_2_t_1_t plc::TYPE::field_2_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_inheriting_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::TYPE::field_3_t_1_t plc::TYPE::field_3_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_implementing_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<INHERITANCE_LIST>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3));
}

plc::TYPE plc::TYPE::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().TYPE.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_type_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_2_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::optional<field_3_t_1_t>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<parlex::details::document::text<literal_0x7B_t>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<erased<TYPE_SCOPE>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<parlex::details::document::text<literal_0x7D_t>>::build(&*children[6], w);
	return TYPE(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}


parlex::details::recognizer const & plc::TYPE::recognizer() {
	return plange_grammar::get().TYPE.get_recognizer();
}
