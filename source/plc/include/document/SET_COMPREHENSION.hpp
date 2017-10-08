// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SET_COMPREHENSION_HPP
#define INCLUDED_SET_COMPREHENSION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct SET_COMPREHENSION {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;
	std::vector<erased<IC>> field_6;


	explicit SET_COMPREHENSION(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && field_2,
		std::vector<erased<IC>> && field_3,
		std::vector<erased<IC>> && field_4,
		erased<EXPRESSION> && field_5,
		std::vector<erased<IC>> && field_6
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)), field_5(std::move(field_5)), field_6(std::move(field_6)) {}

	SET_COMPREHENSION(SET_COMPREHENSION const & other) = default;
	SET_COMPREHENSION(SET_COMPREHENSION && move) = default;

	static SET_COMPREHENSION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_SET_COMPREHENSION_HPP
