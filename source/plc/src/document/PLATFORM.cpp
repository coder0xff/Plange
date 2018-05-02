// This file was generated using Parlex's cpp_generator

#include "PLATFORM.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
plc::PLATFORM plc::PLATFORM::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<parlex::detail::document::text<literal___t>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>
	>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<std::variant<
		parlex::detail::document::text<parlex::detail::letter_t>,
		parlex::detail::document::text<parlex::detail::number_t>,
		parlex::detail::document::text<literal___t>
	>>>::build(&*children[2], w);
	return PLATFORM(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::PLATFORM::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().PLATFORM));
	return result;
}
