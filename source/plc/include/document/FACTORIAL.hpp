// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FACTORIAL_HPP
#define INCLUDED_FACTORIAL_HPP

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

struct FACTORIAL {
	erased<EXPRESSION> field_1;
	
	std::vector<erased<IC>> field_2;
	


	explicit FACTORIAL(
		erased<EXPRESSION> && field_1, std::vector<erased<IC>> && field_2) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	FACTORIAL(FACTORIAL const & other) = default;
	FACTORIAL(FACTORIAL && move) = default;

	static FACTORIAL build(std::u32string const & document, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_FACTORIAL_HPP
