// This file was generated using Parlex's cpp_generator

#include "HEX.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::HEX plc::HEX::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal_0x_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::hexadecimal_digit_t>>>::build(&*children[2], w);
	return HEX(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::HEX::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().HEX));
	return result;
}
