// This file was generated using Parlex's cpp_generator

#include "SYMMETRIC_DIFFERENCE.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::SYMMETRIC_DIFFERENCE plc::SYMMETRIC_DIFFERENCE::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().SYMMETRIC_DIFFERENCE.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<parlex::detail::document::text<literal_0xE20x8A0x96_t>>::build(&*children[2], w);
	auto v_3 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::detail::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return SYMMETRIC_DIFFERENCE(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}


parlex::detail::recognizer const & plc::SYMMETRIC_DIFFERENCE::recognizer() {
	return plange_grammar::get().SYMMETRIC_DIFFERENCE.get_recognizer();
}
