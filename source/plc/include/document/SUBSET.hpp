// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUBSET_HPP
#define INCLUDED_SUBSET_HPP

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
struct SUBSET_NODE;

struct SUBSET {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic;
	
	val<SUBSET_NODE> subset_node;
	


	explicit SUBSET
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && expression, std::vector<val<IC>> && ic, val<SUBSET_NODE> && subset_node)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), expression(std::move(expression)), ic(std::move(ic)), subset_node(std::move(subset_node)) {}

	SUBSET(SUBSET const & other) = default;
	SUBSET(SUBSET && move) = default;

	static SUBSET build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_SUBSET_HPP
