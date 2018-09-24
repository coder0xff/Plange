﻿// This file was generated using Parlex's cpp_generator

#include "ENUM_ELEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "IDENTIFIER.hpp"

plc::ENUM_ELEMENT::field_1_t plc::ENUM_ELEMENT::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A0x3D_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	return field_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::ENUM_ELEMENT plc::ENUM_ELEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<IDENTIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return ENUM_ELEMENT(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::ENUM_ELEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ENUM_ELEMENT));
	return result;
}
