﻿// This file was generated using Parlex's cpp_generator

#include "INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ARRAY_INVOCATION.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"
#include "TYPE_INVOCATION.hpp"

plc::INVOCATION plc::INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		val<PARENTHETICAL_INVOCATION>,
		val<ARRAY_INVOCATION>,
		val<TYPE_INVOCATION>
	>>::build(&*children[2], w);
	return INVOCATION(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::INVOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().INVOCATION));
	return result;
}
