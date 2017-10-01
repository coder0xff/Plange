// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_PRE_DEC_HPP
#define INCLUDED_PRE_DEC_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct PRE_DEC {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;


	PRE_DEC(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static PRE_DEC build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_PRE_DEC_HPP
