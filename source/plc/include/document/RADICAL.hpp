// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RADICAL_HPP
#define INCLUDED_RADICAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct RADICAL {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;


	explicit RADICAL(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	RADICAL(RADICAL const & other) = default;
	RADICAL(RADICAL && move) = default;

	static RADICAL build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_RADICAL_HPP
