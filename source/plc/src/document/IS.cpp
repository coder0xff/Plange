// This file was generated using Parlex's cpp_generator

#include "IS.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::IS plc::IS::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().IS.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<parlex::details::document::text<literal_is_t>>::build(&*children[2], w);
	auto v_3 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[3], w);
	auto v_4 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[4], w);
	return IS(std::move(v_0), std::move(v_1), std::move(v_2), std::move(v_3), std::move(v_4));
}


parlex::details::recognizer const & plc::IS::recognizer() {
	return plange_grammar::get().IS.get_recognizer();
}
