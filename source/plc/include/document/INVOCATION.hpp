// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INVOCATION_HPP
#define INCLUDED_INVOCATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ARRAY_INVOCATION;
struct EXPRESSION;
struct IC;
struct PARENTHETICAL_INVOCATION;
struct TYPE_INVOCATION;

struct INVOCATION {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<PARENTHETICAL_INVOCATION>,
		val<ARRAY_INVOCATION>,
		val<TYPE_INVOCATION>
	> args;
	


	explicit INVOCATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic, std::variant<
	val<PARENTHETICAL_INVOCATION>,
	val<ARRAY_INVOCATION>,
	val<TYPE_INVOCATION>
> const & args)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), ic(ic), args(args) {}

	INVOCATION(INVOCATION const & other) = default;
	static INVOCATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_INVOCATION_HPP
