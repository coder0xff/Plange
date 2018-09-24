// This file was generated using Parlex's cpp_generator

#include "PARENTHETICAL_INVOCATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "STANDARD_ARGUMENTS.hpp"

plc::PARENTHETICAL_INVOCATION::field_1_t plc::PARENTHETICAL_INVOCATION::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<STANDARD_ARGUMENTS>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	return field_1_t(std::move(v0), std::move(v1));
}

plc::PARENTHETICAL_INVOCATION plc::PARENTHETICAL_INVOCATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x28_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<parlex::detail::document::text<literal_0x29_t>>::build(&*children[3], w);
	return PARENTHETICAL_INVOCATION(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}


parlex::detail::acceptor const & plc::PARENTHETICAL_INVOCATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PARENTHETICAL_INVOCATION));
	return result;
}
