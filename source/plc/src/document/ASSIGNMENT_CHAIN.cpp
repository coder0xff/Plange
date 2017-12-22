// This file was generated using Parlex's cpp_generator

#include "ASSIGNMENT_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "ASSIGNMENT_CHAIN.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "XML_DOC_STRING.hpp"

plc::ASSIGNMENT_CHAIN::field_1_t_1_t plc::ASSIGNMENT_CHAIN::field_1_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<XML_DOC_STRING>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::ASSIGNMENT_CHAIN plc::ASSIGNMENT_CHAIN::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASSIGNMENT_CHAIN.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[4], w);
	auto v_5 = parlex::detail::document::element<std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	>>::build(&*children[5], w);
	return ASSIGNMENT_CHAIN(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4), std::move(v_5));
}


parlex::detail::recognizer const & plc::ASSIGNMENT_CHAIN::recognizer() {
	return plange_grammar::get().ASSIGNMENT_CHAIN.get_recognizer();
}
