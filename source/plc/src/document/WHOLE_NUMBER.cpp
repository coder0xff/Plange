// This file was generated using Parlex's cpp_generator

#include "WHOLE_NUMBER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "NON_ZERO_DECIMAL_DIGIT.hpp"

plc::WHOLE_NUMBER plc::WHOLE_NUMBER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<parlex::detail::document::text<literal_0_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<val<NON_ZERO_DECIMAL_DIGIT>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<parlex::detail::document::text<parlex::detail::decimal_digit_t>>>::build(&*children[2], w);
	return WHOLE_NUMBER(n.document_position, n.consumed_character_count, v0, v1, v2);
}


parlex::detail::acceptor const & plc::WHOLE_NUMBER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().WHOLE_NUMBER));
	return result;
}
