// This file was generated using Parlex's cpp_generator

#include "HEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

plc::HEX plc::HEX::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().HEX.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<parlex::details::document::text<literal_0x_t>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<parlex::details::document::text<parlex::details::hexadecimal_digit_t>>::build(&*children[1], w);
	auto v_2 = parlex::details::document::element<std::vector<parlex::details::document::text<parlex::details::hexadecimal_digit_t>>>::build(&*children[2], w);
	return HEX(std::move(v_0), std::move(v_1), std::move(v_2));
}


parlex::details::recognizer const & plc::HEX::recognizer() {
	return plange_grammar::get().HEX.get_recognizer();
}
