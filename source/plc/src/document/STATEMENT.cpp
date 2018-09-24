// This file was generated using Parlex's cpp_generator

#include "STATEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/detail/document.hpp"
#include "ASSIGNMENT_CHAIN.hpp"
#include "BREAK.hpp"
#include "CONTINUE.hpp"
#include "DEFINITION.hpp"
#include "DO.hpp"
#include "EXPRESSION.hpp"
#include "FOR.hpp"
#include "FOR_COLLECTION.hpp"
#include "FREE.hpp"
#include "IC.hpp"
#include "IMPORT.hpp"
#include "LOCK.hpp"
#include "LOOP.hpp"
#include "OP_ASSIGNMENT.hpp"
#include "READ_LOCK.hpp"
#include "RETURN.hpp"
#include "THROW.hpp"
#include "TRY.hpp"
#include "TYPE_CONSTRAINT.hpp"
#include "USING.hpp"
#include "WRITE_LOCK.hpp"

plc::STATEMENT plc::STATEMENT::build(parlex::detail::ast_node const & n) {
	static auto const * b = acceptor().behavior;
	parlex::detail::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b->children;
	auto v0 = parlex::detail::document::element<std::variant<
		val<ASSIGNMENT_CHAIN>,
		val<BREAK>,
		val<CONTINUE>,
		val<DEFINITION>,
		val<DO>,
		val<EXPRESSION>,
		val<FOR>,
		val<FOR_COLLECTION>,
		val<FREE>,
		val<IMPORT>,
		val<LOCK>,
		val<LOOP>,
		val<OP_ASSIGNMENT>,
		val<READ_LOCK>,
		val<RETURN>,
		val<THROW>,
		val<TRY>,
		val<TYPE_CONSTRAINT>,
		val<WRITE_LOCK>,
		val<USING>
	>>::build(&*children[0], w);
	auto v1 = parlex::detail::document::element<std::vector<val<IC>>>::build(&*children[1], w);
	auto v2 = parlex::detail::document::element<parlex::detail::document::text<literal_0x3B_t>>::build(&*children[2], w);
	return STATEMENT(n.document_position, n.consumed_character_count, std::move(v0), std::move(v1), std::move(v2));
}


parlex::detail::acceptor const & plc::STATEMENT::acceptor() {
	static auto const & result = *static_cast<parlex::detail::acceptor const *>(&plange_grammar::get().get_recognizer(plange_grammar::get().STATEMENT));
	return result;
}
