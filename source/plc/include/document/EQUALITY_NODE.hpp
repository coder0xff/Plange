﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EQUALITY_NODE_HPP
#define INCLUDED_EQUALITY_NODE_HPP

#include <optional>
#include <variant>
#include <vector>

#include "val.hpp"

#include "parlex/detail/abstract_syntax_tree.hpp"
#include "parlex/detail/builtins.hpp"
#include "parlex/detail/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EQUALITY_NODE;
struct EXPRESSION;
struct IC;

struct EQUALITY_NODE {
	int32_t document_position, consumed_character_count;

	struct field_2_t {
		std::vector<val<IC>> field_1;
		
		val<EQUALITY_NODE> equality_node;
		
	
	
		explicit field_2_t
			(std::vector<val<IC>> && field_1, val<EQUALITY_NODE> && equality_node)
			: field_1(std::move(field_1)), equality_node(std::move(equality_node)) {}
	
		field_2_t(field_2_t const & other) = default;
		field_2_t(field_2_t && move) = default;
	
		static field_2_t build(parlex::detail::node const * b, parlex::detail::document::walk & w);
	};

	parlex::detail::document::text<literal_0x3D_t> dont_care0;
	
	std::vector<val<IC>> field_1;
	
	val<EXPRESSION> expression;
	
	std::optional<field_2_t> field_2;
	


	explicit EQUALITY_NODE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3D_t> && dont_care0, std::vector<val<IC>> && field_1, val<EXPRESSION> && expression, std::optional<field_2_t> && field_2)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), field_1(std::move(field_1)), expression(std::move(expression)), field_2(std::move(field_2)) {}

	EQUALITY_NODE(EQUALITY_NODE const & other) = default;
	EQUALITY_NODE(EQUALITY_NODE && move) = default;

	static EQUALITY_NODE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_EQUALITY_NODE_HPP