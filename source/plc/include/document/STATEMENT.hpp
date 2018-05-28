// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATEMENT_HPP
#define INCLUDED_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASSIGNMENT_CHAIN;
struct BREAK;
struct CONTINUE;
struct DEFINITION;
struct DO;
struct EXPRESSION;
struct FOR;
struct FOR_COLLECTION;
struct FREE;
struct IC;
struct IMPORT;
struct LOCK;
struct LOOP;
struct OP_ASSIGNMENT;
struct READ_LOCK;
struct RETURN;
struct THROW;
struct TRY;
struct TYPE_CONSTRAINT;
struct USING;
struct WRITE_LOCK;

struct STATEMENT {
	std::variant<
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
		erased<OP_ASSIGNMENT>,
		erased<READ_LOCK>,
		erased<RETURN>,
		erased<THROW>,
		erased<TRY>,
		erased<TYPE_CONSTRAINT>,
		erased<WRITE_LOCK>,
		erased<USING>
	> value;
	
	std::vector<erased<IC>> ic;
	
	parlex::detail::document::text<literal_0x3B_t> dontCare2;
	


	explicit STATEMENT(
		std::variant<
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
			erased<OP_ASSIGNMENT>,
			erased<READ_LOCK>,
			erased<RETURN>,
			erased<THROW>,
			erased<TRY>,
			erased<TYPE_CONSTRAINT>,
			erased<WRITE_LOCK>,
			erased<USING>
		> && value, std::vector<erased<IC>> && ic, parlex::detail::document::text<literal_0x3B_t> && dontCare2) : value(std::move(value)), ic(std::move(ic)), dontCare2(std::move(dontCare2)) {}

	STATEMENT(STATEMENT const & other) = default;
	STATEMENT(STATEMENT && move) = default;

	static STATEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_STATEMENT_HPP
