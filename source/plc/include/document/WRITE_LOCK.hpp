// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_WRITE_LOCK_HPP
#define INCLUDED_WRITE_LOCK_HPP

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

struct WRITE_LOCK {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_write_lock_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<PARENTHETICAL> field_2;
	
	std::vector<val<IC>> field_3;
	
	val<EXPRESSION> field_4;
	


	explicit WRITE_LOCK
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_write_lock_t> && dont_care0, std::vector<val<IC>> && field_1, val<PARENTHETICAL> && field_2, std::vector<val<IC>> && field_3, val<EXPRESSION> && field_4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	WRITE_LOCK(WRITE_LOCK const & other) = default;
	WRITE_LOCK(WRITE_LOCK && move) = default;

	static WRITE_LOCK build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_WRITE_LOCK_HPP
