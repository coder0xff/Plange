// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_VECTOR_NORM_HPP
#define INCLUDED_VECTOR_NORM_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct VECTOR_NORM {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<erased<IC>> field_3;


	explicit VECTOR_NORM(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && field_2,
		std::vector<erased<IC>> && field_3
	) : field_1(std::move(field_1)), field_2(std::move(field_2)), field_3(std::move(field_3)) {}

	VECTOR_NORM(VECTOR_NORM const & other) = default;
	VECTOR_NORM(VECTOR_NORM && move) = default;

	static VECTOR_NORM build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_VECTOR_NORM_HPP
