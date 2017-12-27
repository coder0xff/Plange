// This file was generated using Parlex's cpp_generator

#include "ICR.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"

plc::ICR plc::ICR::build(parlex::detail::ast_node const & n) {
	static auto const * b = state_machine().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<IC>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	return ICR(std::move(v0), std::move(v1));
}


parlex::detail::state_machine const & plc::ICR::state_machine() {
	static auto const & result = *static_cast<parlex::detail::state_machine const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().ICR));
	return result;
}
