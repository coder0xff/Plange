// This file was generated using Parlex's cpp_generator

#include "ASM_IDENTIFIER.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IDENTIFIER.hpp"

plc::ASM_IDENTIFIER plc::ASM_IDENTIFIER::build(parlex::details::ast_node const & n) {
	static auto const * b = &plange_grammar::get().ASM_IDENTIFIER.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->get_children();
	auto v_0 = parlex::details::document::element<std::optional<parlex::details::document::text<literal_0x25_t>>>::build(&*children[0], w);
	auto v_1 = parlex::details::document::element<erased<IDENTIFIER>>::build(&*children[1], w);
	return ASM_IDENTIFIER(std::move(v_0), std::move(v_1));
}


parlex::details::recognizer const & plc::ASM_IDENTIFIER::recognizer() {
	return plange_grammar::get().ASM_IDENTIFIER.get_recognizer();
}
