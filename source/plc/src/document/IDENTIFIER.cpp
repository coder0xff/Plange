// This file was generated using Parlex's cpp_generator

#include "IDENTIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

plc::IDENTIFIER plc::IDENTIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().IDENTIFIER.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<literal___t>
	>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>>>::build(&*children[1], w);
	return IDENTIFIER(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::IDENTIFIER::recognizer() {
	return plange_grammar::get().IDENTIFIER.get_recognizer();
}
