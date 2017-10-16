// This file was generated using Parlex's cpp_generator

#include "STATEMENT.hpp"

#include "plange_grammar.hpp"

#include "parlex/details/document.hpp"
#include "parlex/details/behavior.hpp"

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
#include "READ_LOCK.hpp"
#include "RETURN.hpp"
#include "THROW.hpp"
#include "TRY.hpp"
#include "TYPE_CONSTRAINT.hpp"
#include "USING.hpp"
#include "WRITE_LOCK.hpp"

plc::STATEMENT plc::STATEMENT::build(std::u32string const & document, parlex::details::ast_node const & n) {
	static auto const & b = plange_grammar::get().STATEMENT.get_behavior();
	parlex::details::document::walk w{ n.children.cbegin(), n.children.cend() };
	auto const & children = b.get_children();
	auto v_0 = parlex::details::document::element<std::variant<
		erased<ASSIGNMENT_CHAIN>,
		erased<BREAK>,
		erased<CONTINUE>,
		erased<DEFINITION>,
		erased<DO>,
		erased<EXPRESSION>,
		erased<FOR>,
		erased<FOR_COLLECTION>,
		erased<FREE>,
		erased<IMPORT>,
		erased<LOCK>,
		erased<LOOP>,
		erased<READ_LOCK>,
		erased<RETURN>,
		erased<THROW>,
		erased<TRY>,
		erased<TYPE_CONSTRAINT>,
		erased<WRITE_LOCK>,
		erased<USING>
	>>::build(document, *children[0], w);
	auto v_1 = parlex::details::document::element<std::vector<erased<IC>>>::build(document, *children[1], w);
	assert(w.pos != w.end); ++w.pos; //; 
	return STATEMENT(std::move(v_0), std::move(v_1));
}

