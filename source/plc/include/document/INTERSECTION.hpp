// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_INTERSECTION_HPP
#define INCLUDED_INTERSECTION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct INTERSECTION {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<EXPRESSION> field_4;


	explicit INTERSECTION(
		erased<EXPRESSION> && field_1,
		std::vector<erased<IC>> && field_2,
		std::vector<erased<IC>> && field_3,
		erased<EXPRESSION> && field_4
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)), field_4(std::move(field_4)) {}

	INTERSECTION(INTERSECTION const & other) = default;
	INTERSECTION(INTERSECTION && move) = default;

	static INTERSECTION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_INTERSECTION_HPP
