// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_ASSIGNMENT_NODE_HPP
#define INCLUDED_TYPE_SCOPE_ASSIGNMENT_NODE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct IDENTIFIER_SPECIFICATION;
struct MEMBER_OFFSET;
struct TYPE_SCOPE_ASSIGNMENT_NODE;

struct TYPE_SCOPE_ASSIGNMENT_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		struct field_1_t {
			val<MEMBER_OFFSET> field_1;
			
			std::vector<val<IC>> ic;
			
		
		
			explicit field_1_t
				(val<MEMBER_OFFSET> const & field_1, std::vector<val<IC>> const & ic)
				: field_1(field_1), ic(ic) {}
		
			field_1_t(field_1_t const & other) = default;
			static field_1_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
		};
	
		val<IDENTIFIER_SPECIFICATION> identifier_specification;
		
		std::optional<field_1_t> field_1;
		
		std::vector<val<IC>> field_2;
		
		val<TYPE_SCOPE_ASSIGNMENT_NODE> next;
		
	
	
		explicit field_2_t
			(val<IDENTIFIER_SPECIFICATION> const & identifier_specification, std::optional<field_1_t> const & field_1, std::vector<val<IC>> const & field_2, val<TYPE_SCOPE_ASSIGNMENT_NODE> const & next)
			: identifier_specification(identifier_specification), field_1(field_1), field_2(field_2), next(next) {}
	
		field_2_t(field_2_t const & other) = default;
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<EXPRESSION>,
		field_2_t
	> field_2;
	


	explicit TYPE_SCOPE_ASSIGNMENT_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x860x90_t>,
	parlex::detail::document::text<literal_0x3C0x2D_t>
> const & field_1, std::vector<val<IC>> const & ic, std::variant<
	val<EXPRESSION>,
	field_2_t
> const & field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(field_1), ic(ic), field_2(field_2) {}

	TYPE_SCOPE_ASSIGNMENT_NODE(TYPE_SCOPE_ASSIGNMENT_NODE const & other) = default;
	static TYPE_SCOPE_ASSIGNMENT_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_ASSIGNMENT_NODE_HPP
