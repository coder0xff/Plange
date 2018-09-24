// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NOT_HPP
#define INCLUDED_NOT_HPP

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

struct NOT {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xC20xAC_t>,
		parlex::detail::document::text<literal_0x7E_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit NOT
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xC20xAC_t>,
	parlex::detail::document::text<literal_0x7E_t>
> && field_1, std::vector<val<IC>> && field_2, val<EXPRESSION> && field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	NOT(NOT const & other) = default;
	NOT(NOT && move) = default;

	static NOT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_NOT_HPP
