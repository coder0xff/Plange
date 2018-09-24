// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CAST_HPP
#define INCLUDED_CAST_HPP

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
struct PARENTHETICAL;

struct CAST {
	int32_t document_position, consumed_character_count;

	val<PARENTHETICAL> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit CAST
		(int32_t documentPosition, int32_t consumedCharacterCount, val<PARENTHETICAL> && field_1, std::vector<val<IC>> && field_2, val<EXPRESSION> && field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	CAST(CAST const & other) = default;
	CAST(CAST && move) = default;

	static CAST build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CAST_HPP
