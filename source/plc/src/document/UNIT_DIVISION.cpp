// This file was generated using Parlex's cpp_generator

#include "UNIT_DIVISION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "DIMENSION.hpp"

plc::UNIT_DIVISION plc::UNIT_DIVISION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2F_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[2], w);
	return UNIT_DIVISION(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::UNIT_DIVISION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNIT_DIVISION));
	return result;
}
