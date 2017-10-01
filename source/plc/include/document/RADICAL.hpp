// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RADICAL_HPP
#define INCLUDED_RADICAL_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct RADICAL {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;


	RADICAL(
		std::vector<erased<IC>> const & field_1,
		erased<EXPRESSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static RADICAL build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_RADICAL_HPP
