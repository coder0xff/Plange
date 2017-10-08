// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUBTRACTION_HPP
#define INCLUDED_SUBTRACTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct SUBTRACTION {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<EXPRESSION> field_4;


	explicit SUBTRACTION(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2,
		std::vector<erased<IC>> && field_3,
		erased<EXPRESSION> && field_4
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	SUBTRACTION(SUBTRACTION const & other) = default;
	SUBTRACTION(SUBTRACTION && move) = default;

	static SUBTRACTION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_SUBTRACTION_HPP
