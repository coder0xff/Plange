﻿// This file was generated using Parlex's cpp_generator

#include "CROSS_PRODUCT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::CROSS_PRODUCT plc::CROSS_PRODUCT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xC30x97_t>,
		parlex::detail::document::text<literal__x__t>
	>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<val<EXPRESSION>>::build(&*children[4], w);
	return CROSS_PRODUCT(n.document_position, n.consumed_character_count, v0, v1, v2, v3, v4);
}


parlex::detail::acceptor const & plc::CROSS_PRODUCT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().CROSS_PRODUCT));
	return result;
}
