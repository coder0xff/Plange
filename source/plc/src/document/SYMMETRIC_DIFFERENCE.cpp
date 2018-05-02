// This file was generated using Parlex's cpp_generator

#include "SYMMETRIC_DIFFERENCE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::SYMMETRIC_DIFFERENCE plc::SYMMETRIC_DIFFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8A0x96_t>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return SYMMETRIC_DIFFERENCE(std::move(v0), std::move(v1), std::move(v2), std::move(v3), std::move(v4));
}


parlex::detail::acceptor const & plc::SYMMETRIC_DIFFERENCE::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().SYMMETRIC_DIFFERENCE));
	return result;
}
