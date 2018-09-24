// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_STATEMENT_HPP
#define INCLUDED_STATEMENT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

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
	int32_t document_position, consumed_character_count;

	std::variant<
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
	> value;
	
	std::vector<val<IC>> ic;
	
	parlex::detail::document::text<literal_0x3B_t> dont_care2;
	


	explicit STATEMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
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
> && value, std::vector<val<IC>> && ic, parlex::detail::document::text<literal_0x3B_t> && dont_care2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), value(std::move(value)), ic(std::move(ic)), dont_care2(std::move(dont_care2)) {}

	STATEMENT(STATEMENT const & other) = default;
	STATEMENT(STATEMENT && move) = default;

	static STATEMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_STATEMENT_HPP
