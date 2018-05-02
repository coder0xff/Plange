// This file was generated using Parlex's cpp_generator

#include "ASM_IDENTIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IDENTIFIER.hpp"

plc::ASM_IDENTIFIER plc::ASM_IDENTIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x25_t>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	return ASM_IDENTIFIER(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::ASM_IDENTIFIER::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ASM_IDENTIFIER));
	return result;
}
