﻿// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PARENTHETICAL_HPP
#define INCLUDED_PARENTHETICAL_HPP

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

struct PARENTHETICAL {
	parlex::detail::document::text<literal_0x28_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<EXPRESSION> field_2;
	
	std::vector<erased<IC>> field_3;
	
	parlex::detail::document::text<literal_0x29_t> dontCare4;
	


	explicit PARENTHETICAL(
		parlex::detail::document::text<literal_0x28_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<EXPRESSION> && field_2, std::vector<erased<IC>> && field_3, parlex::detail::document::text<literal_0x29_t> && dontCare4) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), dontCare4(std::move(dontCare4)) {}

	PARENTHETICAL(PARENTHETICAL const & other) = default;
	PARENTHETICAL(PARENTHETICAL && move) = default;

	static PARENTHETICAL build(parlex::detail::ast_node const & n);
	static parlex::detail::state_machine const & state_machine();

};


} // namespace plc



#endif //INCLUDED_PARENTHETICAL_HPP
