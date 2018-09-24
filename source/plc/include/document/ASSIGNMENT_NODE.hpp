// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASSIGNMENT_NODE_HPP
#define INCLUDED_ASSIGNMENT_NODE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct ASSIGNMENT_NODE;
struct EXPRESSION;
struct IC;
struct IDENTIFIER_SPECIFICATION;

struct ASSIGNMENT_NODE {
	int32_t document_position, consumed_character_count;

	struct value_t {
		val<IDENTIFIER_SPECIFICATION> identifier_specification;
		
		std::vector<val<IC>> ic;
		
		val<ASSIGNMENT_NODE> next;
		
	
	
		explicit value_t
			(val<IDENTIFIER_SPECIFICATION> && identifier_specification, std::vector<val<IC>> && ic, val<ASSIGNMENT_NODE> && next)
			: identifier_specification(std::move(identifier_specification)), ic(std::move(ic)), next(std::move(next)) {}
	
		value_t(value_t const & other) = default;
		value_t(value_t && move) = default;
	
		static value_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	std::variant<
		parlex::detail::document::text<literal_0xE20x860x90_t>,
		parlex::detail::document::text<literal_0x3C0x2D_t>
	> field_1;
	
	std::vector<val<IC>> ic;
	
	std::variant<
		val<EXPRESSION>,
		value_t
	> value;
	


	explicit ASSIGNMENT_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x860x90_t>,
	parlex::detail::document::text<literal_0x3C0x2D_t>
> && field_1, std::vector<val<IC>> && ic, std::variant<
	val<EXPRESSION>,
	value_t
> && value)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), ic(std::move(ic)), value(std::move(value)) {}

	ASSIGNMENT_NODE(ASSIGNMENT_NODE const & other) = default;
	ASSIGNMENT_NODE(ASSIGNMENT_NODE && move) = default;

	static ASSIGNMENT_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_ASSIGNMENT_NODE_HPP
