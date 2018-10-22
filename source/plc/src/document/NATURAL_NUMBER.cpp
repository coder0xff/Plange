// This file was generated using Parlex's cpp_generator

#include "NATURAL_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::NATURAL_NUMBER plc::NATURAL_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<parlex::detail::decimal_digit_t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[1], w);
	return NATURAL_NUMBER(n.document_position, n.consumed_character_count, v0, v1);
}


parlex::detail::acceptor const & plc::NATURAL_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().NATURAL_NUMBER));
	return result;
}
