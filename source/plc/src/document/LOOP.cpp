// This file was generated using Parlex's cpp_generator

#include "LOOP.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"
#include "PARENTHETICAL.hpp"

plc::LOOP plc::LOOP::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_while_t>,
		parlex::detail::document::text<literal_until_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<PARENTHETICAL>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return LOOP(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4));
}


parlex::detail::acceptor const & plc::LOOP::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().LOOP));
	return result;
}
