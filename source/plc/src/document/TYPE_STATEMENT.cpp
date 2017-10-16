// This file was generated using Parlex's cpp_generator

#include "TYPE_STATEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

#include "IC.hpp"
#include "STATEMENT.hpp"
#include "TYPE_SCOPE_TYPE_CONSTRAINT.hpp"
#include "VISIBILITY_MODIFIER.hpp"

#include "TYPE_STATEMENT.hpp"

namespace plc {

TYPE_STATEMENT TYPE_STATEMENT::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().TYPE_STATEMENT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	return TYPE_STATEMENT(parlex::details::document::element<TYPE_STATEMENT_base>::build(document, b, w));
}

} // namespace plc
plc::TYPE_STATEMENT_1_t plc::TYPE_STATEMENT_1_t::build(std::u32string const & document, parlex::details::behavior::node const & b, parlex::details::document::walk & w) {
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<erased<VISIBILITY_MODIFIER>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //: 
	return TYPE_STATEMENT_1_t(std::move(v_0), std::move(v_1));
}

