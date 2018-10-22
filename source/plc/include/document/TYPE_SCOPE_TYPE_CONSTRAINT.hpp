// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_HPP

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
struct TYPE_CONSTRAINT_SPECIFICATION;
struct TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT;

struct TYPE_SCOPE_TYPE_CONSTRAINT {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		std::vector<val<IC>> ic1;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::vector<val<IC>> ic2;
		
		val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> field_1;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> const & ic1, parlex::detail::document::text<literal_0x2C_t> const & comma, std::vector<val<IC>> const & ic2, val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> const & field_1)
			: ic1(ic1), comma(comma), ic2(ic2), field_1(field_1) {}
	
		tail_t(tail_t const & other) = default;
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<TYPE_CONSTRAINT_SPECIFICATION> constraint;
	
	std::vector<val<IC>> ic;
	
	val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> head;
	
	std::vector<tail_t> tail;
	


	explicit TYPE_SCOPE_TYPE_CONSTRAINT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<TYPE_CONSTRAINT_SPECIFICATION> const & constraint, std::vector<val<IC>> const & ic, val<TYPE_SCOPE_TYPE_CONSTRAINT_ELEMENT> const & head, std::vector<tail_t> const & tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), constraint(constraint), ic(ic), head(head), tail(tail) {}

	TYPE_SCOPE_TYPE_CONSTRAINT(TYPE_SCOPE_TYPE_CONSTRAINT const & other) = default;
	static TYPE_SCOPE_TYPE_CONSTRAINT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_HPP
