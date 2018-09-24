// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_ASSIGNMENT_HPP
#define INCLUDED_TYPE_SCOPE_ASSIGNMENT_HPP

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
struct TYPE_SCOPE_ASSIGNMENT_NODE;

struct TYPE_SCOPE_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	struct field_1_t {
		val<MEMBER_OFFSET> member_offset;
		
		std::vector<val<IC>> ic;
		
	
	
		explicit field_1_t
			(val<MEMBER_OFFSET> && member_offset, std::vector<val<IC>> && ic)
			: member_offset(std::move(member_offset)), ic(std::move(ic)) {}
	
		field_1_t(field_1_t const & other) = default;
		field_1_t(field_1_t && move) = default;
	
		static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<IDENTIFIER_SPECIFICATION> identifier_specification;
	
	std::vector<val<IC>> ic;
	
	std::optional<field_1_t> field_1;
	
	val<TYPE_SCOPE_ASSIGNMENT_NODE> type_scope_assignment_node;
	


	explicit TYPE_SCOPE_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<IDENTIFIER_SPECIFICATION> && identifier_specification, std::vector<val<IC>> && ic, std::optional<field_1_t> && field_1, val<TYPE_SCOPE_ASSIGNMENT_NODE> && type_scope_assignment_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), identifier_specification(std::move(identifier_specification)), ic(std::move(ic)), field_1(std::move(field_1)), type_scope_assignment_node(std::move(type_scope_assignment_node)) {}

	TYPE_SCOPE_ASSIGNMENT(TYPE_SCOPE_ASSIGNMENT const & other) = default;
	TYPE_SCOPE_ASSIGNMENT(TYPE_SCOPE_ASSIGNMENT && move) = default;

	static TYPE_SCOPE_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_ASSIGNMENT_HPP
