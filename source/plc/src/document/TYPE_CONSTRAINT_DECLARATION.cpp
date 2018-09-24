﻿// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_DECLARATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "IDENTIFIER_SPECIFICATION.hpp"
#include "PARENTHETICAL_INVOCATION.hpp"

plc::TYPE_CONSTRAINT_DECLARATION::args_t plc::TYPE_CONSTRAINT_DECLARATION::args_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<PARENTHETICAL_INVOCATION>>::build(&*children[1], w);
	return args_t(std::move(v0), std::move(v1));
}

plc::TYPE_CONSTRAINT_DECLARATION plc::TYPE_CONSTRAINT_DECLARATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER_SPECIFICATION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<args_t>>::build(&*children[1], w);
	return TYPE_CONSTRAINT_DECLARATION(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::TYPE_CONSTRAINT_DECLARATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT_DECLARATION));
	return result;
}