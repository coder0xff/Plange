// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LESSER_HPP
#define INCLUDED_LESSER_HPP

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
struct LESSER_NODE;

struct LESSER {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	val<LESSER_NODE> lesser_node;
	


	explicit LESSER
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> const & expression, std::vector<val<IC>> const & ic, val<LESSER_NODE> const & lesser_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(expression), ic(ic), lesser_node(lesser_node) {}

	LESSER(LESSER const & other) = default;
	static LESSER build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_LESSER_HPP
