﻿// This file was generated using Parlex's cpp_generator

#include "SET_COMPREHENSION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::SET_COMPREHENSION plc::SET_COMPREHENSION::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7B_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7C_t>>::build(&*children[4], w);
	auto v5 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[5], w);
	auto v6 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[6], w);
	auto v7 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[7], w);
	auto v8 = parlex::detail::document::element<parlex::detail::document::text<literal_0x7D_t>>::build(&*children[8], w);
	return SET_COMPREHENSION(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4), std::move(v5), std::move(v6), std::move(v7), std::move(v8));
}


parlex::detail::state_machine const & plc::SET_COMPREHENSION::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SET_COMPREHENSION));
	return result;
}
