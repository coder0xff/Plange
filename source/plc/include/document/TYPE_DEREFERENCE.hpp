﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_DEREFERENCE_HPP
#define INCLUDED_TYPE_DEREFERENCE_HPP

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

struct TYPE_DEREFERENCE {
	int32_t document_position, consumed_character_count;

	parlex::detail::document::text<literal_0x3C_t> dont_care0;
	
	std::vector<val<IC>> ic1;
	
	val<EXPRESSION> expression;
	
	std::vector<val<IC>> ic2;
	
	parlex::detail::document::text<literal_0x3E_t> dont_care4;
	


	explicit TYPE_DEREFERENCE
		(int32_t documentPosition, int32_t consumedCharacterCount, parlex::detail::document::text<literal_0x3C_t> && dont_care0, std::vector<val<IC>> && ic1, val<EXPRESSION> && expression, std::vector<val<IC>> && ic2, parlex::detail::document::text<literal_0x3E_t> && dont_care4)
		: document_position(documentPosition), consumed_character_count(consumedCharacterCount), dont_care0(std::move(dont_care0)), ic1(std::move(ic1)), expression(std::move(expression)), ic2(std::move(ic2)), dont_care4(std::move(dont_care4)) {}

	TYPE_DEREFERENCE(TYPE_DEREFERENCE const & other) = default;
	TYPE_DEREFERENCE(TYPE_DEREFERENCE && move) = default;

	static TYPE_DEREFERENCE build(parlex::detail::ast_node const & n);
	static parlex::detail::acceptor const & acceptor();

};


} // namespace plc



#endif //INCLUDED_TYPE_DEREFERENCE_HPP
