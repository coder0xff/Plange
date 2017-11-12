// This file was generated using Parlex's cpp_generator

#include "PLATFORM.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::PLATFORM plc::PLATFORM::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().PLATFORM.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal___t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<std::variant<
		parlex::details::document::text<parlex::details::letter_t>,
		parlex::details::document::text<parlex::details::number_t>
	>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<std::variant<
		parlex::details::document::text<parlex::details::letter_t>,
		parlex::details::document::text<parlex::details::number_t>,
		parlex::details::document::text<literal___t>
	>>>::build(&*children[2], w);
	return PLATFORM(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::PLATFORM::recognizer() {
	return plange_grammar::get().PLATFORM.get_recognizer();
}
