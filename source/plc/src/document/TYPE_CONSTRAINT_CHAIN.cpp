// This file was generated using Parlex's cpp_generator

#include "TYPE_CONSTRAINT_CHAIN.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASSIGNMENT_CHAIN.hpp"
#include "DECLARATION.hpp"
#include "DEFINITION.hpp"
#include "IC.hpp"
#include "TYPE_CONSTRAINT_CHAIN.hpp"

plc::TYPE_CONSTRAINT_CHAIN::field_2_t_1_t plc::TYPE_CONSTRAINT_CHAIN::field_2_t_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<parlex::detail::document::text<literal_0x2C_t>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[2], w);
	auto v3 = parlex::detail::document::element<erased<TYPE_CONSTRAINT_CHAIN>>::build(&*children[3], w);
	return field_2_t_1_t(std::move(v0), std::move(v1), std::move(v2), std::move(v3));
}

plc::TYPE_CONSTRAINT_CHAIN plc::TYPE_CONSTRAINT_CHAIN::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		erased<DECLARATION>,
		erased<ASSIGNMENT_CHAIN>,
		erased<DEFINITION>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::optional<field_2_t_1_t>>::build(&*children[1], w);
	return TYPE_CONSTRAINT_CHAIN(std::move(v0), std::move(v1));
}


parlex::detail::acceptor const & plc::TYPE_CONSTRAINT_CHAIN::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_CONSTRAINT_CHAIN));
	return result;
}
