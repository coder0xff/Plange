// This file was generated using Parlex's cpp_generator

#include "UNIT_DIVISION.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DIMENSION.hpp"

plc::UNIT_DIVISION plc::UNIT_DIVISION::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().UNIT_DIVISION.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<DIMENSION>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_0x2F_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<DIMENSION>>::build(&*children[2], w);
	return UNIT_DIVISION(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::UNIT_DIVISION::recognizer() {
	return plange_grammar::get().UNIT_DIVISION.get_recognizer();
}
