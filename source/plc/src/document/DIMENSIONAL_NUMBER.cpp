// This file was generated using Parlex's cpp_generator

#include "DIMENSIONAL_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "DIMENSION.hpp"
#include "NON_NEG_NUMBER.hpp"

plc::DIMENSIONAL_NUMBER plc::DIMENSIONAL_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<NON_NEG_NUMBER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[1], w);
	return DIMENSIONAL_NUMBER(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::DIMENSIONAL_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().DIMENSIONAL_NUMBER));
	return result;
}
