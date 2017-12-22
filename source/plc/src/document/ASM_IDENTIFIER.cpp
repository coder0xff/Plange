// This file was generated using Parlex's cpp_generator

#include "ASM_IDENTIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "parlex/detail/behavior.hpp"

#include "IDENTIFIER.hpp"

plc::ASM_IDENTIFIER plc::ASM_IDENTIFIER::build(parlex::detail::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_IDENTIFIER.get_behavior();
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::detail::document::element<std::optional<parlex::detail::document::text<literal_0x25_t>>>::build(&*children[0], w);
	auto v_1 = parlex::detail::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	return ASM_IDENTIFIER(std::move(v_0), std::move(v_1));
}


parlex::detail::recognizer const & plc::ASM_IDENTIFIER::recognizer() {
	return plange_grammar::get().ASM_IDENTIFIER.get_recognizer();
}
