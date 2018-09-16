﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CROSS_PRODUCT_HPP
#define INCLUDED_CROSS_PRODUCT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct CROSS_PRODUCT {
	int32_t document_position, consumed_character_count;

	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	
	std::variant<
		parlex::detail::document::text<literal_0xC30x97_t>,
		parlex::detail::document::text<literal__x__t>
	> field_3;
	
	std::vector<erased<IC>> field_4;
	
	erased<EXPRESSION> field_5;
	


	explicit CROSS_PRODUCT
		(int32_t documentPosition, int32_t consumedCharacterCount, erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2, std::variant<
	parlex::detail::document::text<literal_0xC30x97_t>,
	parlex::detail::document::text<literal__x__t>
> && field_3, std::vector<erased<IC>> && field_4, erased<EXPRESSION> && field_5)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)) {}

	CROSS_PRODUCT(CROSS_PRODUCT const & other) = default;
	CROSS_PRODUCT(CROSS_PRODUCT && move) = default;

	static CROSS_PRODUCT build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_CROSS_PRODUCT_HPP
