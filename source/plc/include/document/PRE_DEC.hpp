// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PRE_DEC_HPP
#define INCLUDED_PRE_DEC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct PRE_DEC {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;


	explicit PRE_DEC(
		std::vector<erased<IC>> && field_1,
		erased<EXPRESSION> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	PRE_DEC(PRE_DEC const & other) = default;
	PRE_DEC(PRE_DEC && move) = default;

	static PRE_DEC build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_PRE_DEC_HPP
