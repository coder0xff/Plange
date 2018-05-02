// This file was generated using Parlex's cpp_generator

#include "TYPE_STATEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "IC.hpp"
#include "STATEMENT.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT.hpp"
#include "VISIBILITY_MODIFIER.hpp"

#include "TYPE_STATEMENT.hpp"

namespace plc {

TYPE_STATEMENT TYPE_STATEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	return TYPE_STATEMENT(parlex::detail::document::element<TYPE_STATEMENT_base>::build(b, w));
}

} // namespace plc
plc::TYPE_STATEMENT_1_t plc::TYPE_STATEMENT_1_t::build(parlex::detail::node const * b, parlex::detail::document::walk & w) {
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<erased<VISIBILITY_MODIFIER>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<erased<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3A_t>>::build(&*children[2], w);
	return TYPE_STATEMENT_1_t(std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::TYPE_STATEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().TYPE_STATEMENT));
	return result;
}
