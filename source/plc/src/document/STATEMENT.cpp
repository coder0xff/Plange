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
plc::STATEMENT plc::STATEMENT::build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n) {
	auto const & children = b.get_children();
	return STATEMENT(
		parlex::details::document::element<decltype(field_1)>::build(*children[0], n.children[0]),
		parlex::details::document::element<decltype(field_2)>::build(*children[0], n.children[0])
);
}

