// This file was generated using Parlex's cpp_generator

#include "UNIT_EXPONENTIATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "DIMENSION.hpp"
#include "NON_FRACTIONAL.hpp"

plc::UNIT_EXPONENTIATION plc::UNIT_EXPONENTIATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().UNIT_EXPONENTIATION.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x5E_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<NON_FRACTIONAL>>::build(&*children[2], w);
	return UNIT_EXPONENTIATION(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::UNIT_EXPONENTIATION::recognizer() {
	return plange_grammar::get().UNIT_EXPONENTIATION.get_recognizer();
}
