﻿// This file was generated using Parlex's cpp_generator

#include "SUPERSET_NODE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "SUPERSET_NODE.hpp"

plc::SUPERSET_NODE::field_2_t plc::SUPERSET_NODE::field_2_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<SUPERSET_NODE>>::build(&*children[1], w);
	return field_2_t(std::move(v0), std::move(v1));
}

plc::SUPERSET_NODE plc::SUPERSET_NODE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0x3D_t>,
		parlex::detail::document::text<literal_0xE20x8A0x87_t>,
		parlex::detail::document::text<literal_sups_t>,
		parlex::detail::document::text<literal_0xE20x8A0x83_t>,
		parlex::detail::document::text<literal_psups_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::optional<field_2_t>>::build(&*children[3], w);
	return SUPERSET_NODE(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}


parlex::detail::acceptor const & plc::SUPERSET_NODE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SUPERSET_NODE));
	return result;
}