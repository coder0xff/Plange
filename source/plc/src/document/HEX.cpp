// This file was generated using Parlex's cpp_generator

#include "HEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

plc::HEX plc::HEX::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().HEX.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x_t>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>>>::build(&*children[2], w);
	return HEX(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::detail::recognizer const & plc::HEX::recognizer() {
	return plange_grammar::get().HEX.get_recognizer();
}
