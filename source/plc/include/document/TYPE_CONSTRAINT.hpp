// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_HPP
#define INCLUDED_TYPE_CONSTRAINT_HPP

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
struct TYPE_CONSTRAINT_ELEMENT;
struct TYPE_CONSTRAINT_SPECIFICATION;

struct TYPE_CONSTRAINT {
	int32_t document_position, consumed_character_count;

	struct tail_t {
		std::vector<val<IC>> ic1;
		
		parlex::detail::document::text<literal_0x2C_t> comma;
		
		std::vector<val<IC>> ic2;
		
		val<TYPE_CONSTRAINT_ELEMENT> type_constraint_element;
		
	
	
		explicit tail_t
			(std::vector<val<IC>> && ic1, parlex::detail::document::text<literal_0x2C_t> && comma, std::vector<val<IC>> && ic2, val<TYPE_CONSTRAINT_ELEMENT> && type_constraint_element)
			: ic1(std::move(ic1)), comma(std::move(comma)), ic2(std::move(ic2)), type_constraint_element(std::move(type_constraint_element)) {}
	
		tail_t(tail_t const & other) = default;
		tail_t(tail_t && move) = default;
	
		static tail_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	val<TYPE_CONSTRAINT_SPECIFICATION> specification;
	
	std::vector<val<IC>> ic;
	
	val<TYPE_CONSTRAINT_ELEMENT> head;
	
	std::vector<tail_t> tail;
	


	explicit TYPE_CONSTRAINT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<TYPE_CONSTRAINT_SPECIFICATION> && specification, std::vector<val<IC>> && ic, val<TYPE_CONSTRAINT_ELEMENT> && head, std::vector<tail_t> && tail)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), specification(std::move(specification)), ic(std::move(ic)), head(std::move(head)), tail(std::move(tail)) {}

	TYPE_CONSTRAINT(TYPE_CONSTRAINT const & other) = default;
	TYPE_CONSTRAINT(TYPE_CONSTRAINT && move) = default;

	static TYPE_CONSTRAINT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_HPP
