// This file was generated using Parlex's cpp_generator

#include "DATE_TIME.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "DATE.hpp"
#include "TIME.hpp"

plc::DATE_TIME plc::DATE_TIME::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().DATE_TIME.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<erased<DATE>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<literal_T_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<erased<TIME>>::build(&*children[2], w);
	return DATE_TIME(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::DATE_TIME::recognizer() {
	return plange_grammar::get().DATE_TIME.get_recognizer();
}
