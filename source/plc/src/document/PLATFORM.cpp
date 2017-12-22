// This file was generated using Parlex's cpp_generator

#include "PLATFORM.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

plc::PLATFORM plc::PLATFORM::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().PLATFORM.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal___t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>
	>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>>>::build(&*children[2], w);
	return PLATFORM(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::PLATFORM::recognizer() {
	return plange_grammar::get().PLATFORM.get_recognizer();
}
