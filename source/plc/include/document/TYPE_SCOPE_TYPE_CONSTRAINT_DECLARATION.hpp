// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION_HPP

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
struct MEMBER_OFFSET;
struct PARENTHETICAL_INVOCATION;

struct TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION {
	int32_t document_position, consumed_character_count;

	struct args_t {
		std::vector<val<IC>> ic;
		
		val<PARENTHETICAL_INVOCATION> field_1;
		
	
	
		explicit args_t
			(std::vector<val<IC>> const & ic, val<PARENTHETICAL_INVOCATION> const & field_1)
			: ic(ic), field_1(field_1) {}
	
		args_t(args_t const & other) = default;
		static args_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	struct field_1_t {
		std::vector<val<IC>> ic;
		
		val<MEMBER_OFFSET> member_offset;
		
	
	
		explicit field_1_t
			(std::vector<val<IC>> const & ic, val<MEMBER_OFFSET> const & member_offset)
			: ic(ic), member_offset(member_offset) {}
	
		field_1_t(field_1_t const & other) = default;
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::optional<args_t> args;
	
	std::optional<field_1_t> field_1;
	


	explicit TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::optional<args_t> const & args, std::optional<field_1_t> const & field_1)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(identifier_specification), args(args), field_1(field_1) {}

	TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION(TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION const & other) = default;
	static TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_DECLARATION_HPP
