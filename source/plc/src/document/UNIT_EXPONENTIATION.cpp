// This file was generated using Parlex's cpp_generator

#include "UNIT_EXPONENTIATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "DIMENSION.hpp"
#include "NON_FRACTIONAL.hpp"

plc::UNIT_EXPONENTIATION plc::UNIT_EXPONENTIATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<NON_FRACTIONAL>>::build(&*children[2], w);
	return UNIT_EXPONENTIATION(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::UNIT_EXPONENTIATION::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().UNIT_EXPONENTIATION));
	return result;
}
