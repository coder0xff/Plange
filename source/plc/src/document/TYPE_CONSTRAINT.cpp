// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "TYPE_CONSTRAINT_CHAIN.hpp"
#include "TYPE_CONSTRAINT_HEAD.hpp"

plc::TYPE_CONSTRAINT plc::TYPE_CONSTRAINT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<TYPE_CONSTRAINT_HEAD>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<erased<TYPE_CONSTRAINT_CHAIN>>::build(&*children[2], w);
	return TYPE_CONSTRAINT(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::TYPE_CONSTRAINT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT));
	return result;
}
