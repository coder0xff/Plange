﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RADICAL_HPP
#define INCLUDED_RADICAL_HPP

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

struct RADICAL {
	int32_t document_position, consumed_character_count;

	std::variant<
		parlex::detail::document::text<literal_0xE20x880x9A_t>,
		parlex::detail::document::text<literal_sqrt_t>
	> field_1;
	
	std::vector<val<IC>> field_2;
	
	val<EXPRESSION> field_3;
	


	explicit RADICAL
		(int32_t documentPosition, int32_t consumedCharacterCount, std::variant<
	parlex::detail::document::text<literal_0xE20x880x9A_t>,
	parlex::detail::document::text<literal_sqrt_t>
> && field_1, std::vector<val<IC>> && field_2, val<EXPRESSION> && field_3)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	RADICAL(RADICAL const & other) = default;
	RADICAL(RADICAL && move) = default;

	static RADICAL build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_RADICAL_HPP
