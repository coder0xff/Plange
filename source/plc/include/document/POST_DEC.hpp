// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_POST_DEC_HPP
#define INCLUDED_POST_DEC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct POST_DEC {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;


	POST_DEC(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static POST_DEC build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_POST_DEC_HPP
