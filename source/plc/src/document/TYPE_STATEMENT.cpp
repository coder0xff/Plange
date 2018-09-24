// This file was generated using Parlex's cpp_generator

#include "TYPE_STATEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "STATEMENT.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT.hpp"
#include "VISIBILITY_MODIFIER.hpp"

plc::TYPE_STATEMENT::field_1_t1 plc::TYPE_STATEMENT::field_1_t1::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[2], w);
	return field_1_t1(std::move(v0), std::move(v1), std::move(v2));
}

plc::TYPE_STATEMENT plc::TYPE_STATEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		field_1_t1,
		val<TYPE_SCOPE_TYPE_CONSTRAINT>,
		val<STATEMENT>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[1], w);
	return TYPE_STATEMENT(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::TYPE_STATEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_STATEMENT));
	return result;
}
