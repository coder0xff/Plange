// This file was generated using Parlex's cpp_generator

#include "ALL.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "EXPRESSION.hpp"
#include "IC.hpp"

plc::ALL plc::ALL::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ALL.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		parlex::details::document::text<literal_0xE20x880x80_t>,
		parlex::details::document::text<literal_all_t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<erased<EXPRESSION>>::build(&*children[2], w);
	return ALL(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::ALL::recognizer() {
	return plange_grammar::get().ALL.get_recognizer();
}
