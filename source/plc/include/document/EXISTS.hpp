// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXISTS_HPP
#define INCLUDED_EXISTS_HPP

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

struct EXISTS {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xE20x880x83_t>,
		parlex::detail::document::text<literal_exists_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit EXISTS
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x880x83_t>,
	parlex::detail::document::text<literal_exists_t>
> && field_1, std::vector<val<IC>> && field_2, val<EXPRESSION> && field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	EXISTS(EXISTS const & other) = default;
	EXISTS(EXISTS && move) = default;

	static EXISTS build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_EXISTS_HPP
