// This file was generated using Parlex's cpp_generator

#include "DATE_TIME.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "DATE.hpp"
#include "TIME.hpp"

plc::DATE_TIME plc::DATE_TIME::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DATE_TIME.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<erased<DATE>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<literal_T_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<TIME>>::build(&*children[2], w);
	return DATE_TIME(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::DATE_TIME::recognizer() {
	return plange_grammar::get().DATE_TIME.get_recognizer();
}
