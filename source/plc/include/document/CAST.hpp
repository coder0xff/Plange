// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CAST_HPP
#define INCLUDED_CAST_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct CAST {
	erased<PARENTHETICAL> field_1;
	
	std::vector<erased<IC>> field_2;
	
	erased<EXPRESSION> field_3;
	


	explicit CAST(
		erased<PARENTHETICAL> && field_1, std::vector<erased<IC>> && field_2, erased<EXPRESSION> && field_3) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	CAST(CAST const & other) = default;
	CAST(CAST && move) = default;

	static CAST build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_CAST_HPP
