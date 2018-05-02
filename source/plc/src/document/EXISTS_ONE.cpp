// This file was generated using Parlex's cpp_generator

#include "EXISTS_ONE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::EXISTS_ONE plc::EXISTS_ONE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<literal_0xE20x880x830x21_t>,
		parlex::detail::document::text<literal_exists0x21_t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	return EXISTS_ONE(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::EXISTS_ONE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().EXISTS_ONE));
	return result;
}
