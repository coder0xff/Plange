﻿// This file was generated using Parlex's cpp_generator

#include "THIS_TYPE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::THIS_TYPE::field_1_t plc::THIS_TYPE::field_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5B_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5D_t>>::build(&*children[5], w);
	return field_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5));
}

plc::THIS_TYPE plc::THIS_TYPE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_this_type_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_1_t>>::build(&*children[1], w);
	return THIS_TYPE(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::THIS_TYPE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().THIS_TYPE));
	return result;
}
