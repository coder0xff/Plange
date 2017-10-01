// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_KLEENE_STAR_HPP
#define INCLUDED_KLEENE_STAR_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct KLEENE_STAR {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;


	KLEENE_STAR(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static KLEENE_STAR build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_KLEENE_STAR_HPP
