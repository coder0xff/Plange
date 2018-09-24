// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_DECLARATION_HPP
#define INCLUDED_TYPE_CONSTRAINT_DECLARATION_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct IDENTIFIER_SPECIFICATION;
struct PARENTHETICAL_INVOCATION;

struct TYPE_CONSTRAINT_DECLARATION {
	int32_t document_position, consumed_character_count;

	struct args_t {
		std::vector<val<IC>> ic;
		
		val<PARENTHETICAL_INVOCATION> parenthetical_invocation;
		
	
	
		explicit args_t
			(std::vector<val<IC>> && ic, val<PARENTHETICAL_INVOCATION> && parenthetical_invocation)
			: ic(std::move(ic)), parenthetical_invocation(std::move(parenthetical_invocation)) {}
	
		args_t(args_t const & other) = default;
		args_t(args_t && move) = default;
	
		static args_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::optional<args_t> args;
	


	explicit TYPE_CONSTRAINT_DECLARATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> && identifier_specification, std::optional<args_t> && args)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(std::move(identifier_specification)), args(std::move(args)) {}

	TYPE_CONSTRAINT_DECLARATION(TYPE_CONSTRAINT_DECLARATION const & other) = default;
	TYPE_CONSTRAINT_DECLARATION(TYPE_CONSTRAINT_DECLARATION && move) = default;

	static TYPE_CONSTRAINT_DECLARATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_DECLARATION_HPP
