// This file was generated using Parlex's cpp_generator

#include "TYPE_SCOPE_ASSIGNMENT_NODE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER_SPECIFICATION.hpp"
#include "MEMBER_OFFSET.hpp"
#include "TYPE_SCOPE_ASSIGNMENT_NODE.hpp"

plc::TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t::field_1_t plc::TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<MEMBER_OFFSET>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_1_t(std::move(v0), std::move(v1));
}

plc::TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t plc::TYPE_SCOPE_ASSIGNMENT_NODE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<TYPE_SCOPE_ASSIGNMENT_NODE>>::build(&*children[3], w);
	return field_2_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::TYPE_SCOPE_ASSIGNMENT_NODE plc::TYPE_SCOPE_ASSIGNMENT_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		val<EXPRESSION>,
		field_2_t
	>>::build(&*children[2], w);
	return TYPE_SCOPE_ASSIGNMENT_NODE(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::TYPE_SCOPE_ASSIGNMENT_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_SCOPE_ASSIGNMENT_NODE));
	return result;
}
