// This file was generated using Parlex's cpp_generator

#include "TYPE_SCOPE_ASSIGNMENT_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "ASSIGNMENT_CHAIN.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "MEMBER_OFFSET.hpp"
#include "XML_DOC_STRING.hpp"

plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_1_t_1_t plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_1_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<XML_DOC_STRING>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_3_t_1_t plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_3_t_1_t::build(parlex::details::behavior::node const * b, parlex::details::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<MEMBER_OFFSET>>::build(&*children[1], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_SCOPE_ASSIGNMENT_CHAIN plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().TYPE_SCOPE_ASSIGNMENT_CHAIN.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::optional<field_3_t_1_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0xE20x860x90_t>,
		parlex::details::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[4], w);
	auto v_5 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v_6 = parlex::details::document::element<std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	>>::build(&*children[6], w);
	return TYPE_SCOPE_ASSIGNMENT_CHAIN(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5), std::move(v_6));
}


parlex::details::recognizer const & plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::recognizer() {
	return plange_grammar::get().TYPE_SCOPE_ASSIGNMENT_CHAIN.get_recognizer();
}
