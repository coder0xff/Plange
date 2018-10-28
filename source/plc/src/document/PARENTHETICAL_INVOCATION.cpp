// This file was generated using Parlex's cpp_generator

#include "PARENTHETICAL_INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "STANDARD_ARGUMENTS.hpp"

plc::PARENTHETICAL_INVOCATION::arguments_t plc::PARENTHETICAL_INVOCATION::arguments_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<STANDARD_ARGUMENTS>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return arguments_t(v0, v1);
}

plc::PARENTHETICAL_INVOCATION::PARENTHETICAL_INVOCATION(PARENTHETICAL_INVOCATION const & other) : document_position(other.document_position), consumed_character_count(other.consumed_character_count), dont_care0(other.dont_care0), ic(other.ic), arguments(other.arguments), dont_care3(other.dont_care3) {}

plc::PARENTHETICAL_INVOCATION plc::PARENTHETICAL_INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<arguments_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	auto result = PARENTHETICAL_INVOCATION(n.document_position, n.consumed_character_count, v0, v1, v2, v3);
	return result;
}


parlex::detail::acceptor const & plc::PARENTHETICAL_INVOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARENTHETICAL_INVOCATION));
	return result;
}
