// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUPERSET_HPP
#define INCLUDED_SUPERSET_HPP

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
struct SUPERSET_NODE;

struct SUPERSET {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	val<SUPERSET_NODE> superset_node;
	


	explicit SUPERSET
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && expression, std::vector<val<IC>> && ic, val<SUPERSET_NODE> && superset_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(std::move(expression)), ic(std::move(ic)), superset_node(std::move(superset_node)) {}

	SUPERSET(SUPERSET const & other) = default;
	SUPERSET(SUPERSET && move) = default;

	static SUPERSET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_SUPERSET_HPP
