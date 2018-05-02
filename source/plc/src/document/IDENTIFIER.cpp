// This file was generated using Parlex's cpp_generator

#include "IDENTIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::IDENTIFIER plc::IDENTIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<literal___t>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>>>::build(&*children[1], w);
	return IDENTIFIER(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::IDENTIFIER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().IDENTIFIER));
	return result;
}
