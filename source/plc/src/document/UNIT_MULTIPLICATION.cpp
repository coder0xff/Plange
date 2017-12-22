// This file was generated using Parlex's cpp_generator

#include "UNIT_MULTIPLICATION.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "DIMENSION.hpp"

plc::UNIT_MULTIPLICATION plc::UNIT_MULTIPLICATION::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().UNIT_MULTIPLICATION.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2A_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<DIMENSION>>::build(&*children[2], w);
	return UNIT_MULTIPLICATION(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::UNIT_MULTIPLICATION::recognizer() {
	return plange_grammar::get().UNIT_MULTIPLICATION.get_recognizer();
}
