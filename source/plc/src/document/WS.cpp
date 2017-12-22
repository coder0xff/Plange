// This file was generated using Parlex's cpp_generator

#include "WS.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

plc::WS plc::WS::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().WS.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::white_space_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::white_space_t>>>::build(&*children[1], w);
	return WS(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::WS::recognizer() {
	return plange_grammar::get().WS.get_recognizer();
}
