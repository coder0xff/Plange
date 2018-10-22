// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_HPP
#define INCLUDED_GREATER_HPP

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
struct GREATER_NODE;
struct IC;

struct GREATER {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> field_1;
	
	val<GREATER_NODE> greater_node;
	


	explicit GREATER
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & field_1, val<GREATER_NODE> const & greater_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), field_1(field_1), greater_node(greater_node) {}

	GREATER(GREATER const & other) = default;
	static GREATER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_GREATER_HPP
