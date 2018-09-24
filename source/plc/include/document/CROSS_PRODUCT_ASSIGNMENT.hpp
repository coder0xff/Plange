// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CROSS_PRODUCT_ASSIGNMENT_HPP
#define INCLUDED_CROSS_PRODUCT_ASSIGNMENT_HPP

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

struct CROSS_PRODUCT_ASSIGNMENT {
	int32_t document_position, consumed_character_count;

	val<EXPRESSION> field_1;
	
	std::vector<val<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC30x97_t>,
		parlex::detail::document::text<literal__x__t>
	> field_3;
	
	std::variant<
		parlex::detail::document::text<literal_0x3C0x2D_t>,
		parlex::detail::document::text<literal_0xE20x860x90_t>
	> field_4;
	
	std::vector<val<IC>> field_5;
	
	val<EXPRESSION> field_6;
	


	explicit CROSS_PRODUCT_ASSIGNMENT
		(int32_t documentPosition, int32_t consumedCharacterCount, val<EXPRESSION> && field_1, std::vector<val<IC>> && field_2, std::variant<
	parlex::detail::document::text<literal_0xC30x97_t>,
	parlex::detail::document::text<literal__x__t>
> && field_3, std::variant<
	parlex::detail::document::text<literal_0x3C0x2D_t>,
	parlex::detail::document::text<literal_0xE20x860x90_t>
> && field_4, std::vector<val<IC>> && field_5, val<EXPRESSION> && field_6)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}

	CROSS_PRODUCT_ASSIGNMENT(CROSS_PRODUCT_ASSIGNMENT const & other) = default;
	CROSS_PRODUCT_ASSIGNMENT(CROSS_PRODUCT_ASSIGNMENT && move) = default;

	static CROSS_PRODUCT_ASSIGNMENT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CROSS_PRODUCT_ASSIGNMENT_HPP
