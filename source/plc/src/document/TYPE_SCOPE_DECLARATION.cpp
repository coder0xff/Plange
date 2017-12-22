// This file was generated using Parlex's cpp_generator

#include "TYPE_SCOPE_DECLARATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "MEMBER_OFFSET.hpp"
#include "XML_DOC_STRING.hpp"

plc::TYPE_SCOPE_DECLARATION::field_1_t_1_t plc::TYPE_SCOPE_DECLARATION::field_1_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<XML_DOC_STRING>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_SCOPE_DECLARATION::field_3_t_1_t plc::TYPE_SCOPE_DECLARATION::field_3_t_1_t::build(parlex::detail::behavior::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<MEMBER_OFFSET>>::build(&*children[1], w);
	return field_3_t_1_t(std::move(v_0), std::move(v_1));
}

plc::TYPE_SCOPE_DECLARATION plc::TYPE_SCOPE_DECLARATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().TYPE_SCOPE_DECLARATION.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::optional<field_3_t_1_t>>::build(&*children[2], w);
	return TYPE_SCOPE_DECLARATION(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::TYPE_SCOPE_DECLARATION::recognizer() {
	return plange_grammar::get().TYPE_SCOPE_DECLARATION.get_recognizer();
}
