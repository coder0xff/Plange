// This file was generated using Parlex's cpp_generator

#include "TYPE_SCOPE_ASSIGNMENT_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASSIGNMENT_CHAIN.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"
#include "MEMBER_OFFSET.hpp"
#include "XML_DOC_STRING.hpp"

plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_1_t_1_t plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_1_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<XML_DOC_STRING>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return field_1_t_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_3_t_1_t plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::field_3_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<MEMBER_OFFSET>>::build(&*children[1], w);
	return field_3_t_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_SCOPE_ASSIGNMENT_CHAIN plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<field_1_t_1_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_3_t_1_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	>>::build(&*children[6], w);
	return TYPE_SCOPE_ASSIGNMENT_CHAIN(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6));
}


parlex::detail::acceptor const & plc::TYPE_SCOPE_ASSIGNMENT_CHAIN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_ASSIGNMENT_CHAIN));
	return result;
}
