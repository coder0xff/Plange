// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SYMMETRIC_DIFFERENCE_HPP
#define INCLUDED_SYMMETRIC_DIFFERENCE_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct EXPRESSION;
struct IC;

struct SYMMETRIC_DIFFERENCE {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	erased<EXPRESSION> field_4;


	SYMMETRIC_DIFFERENCE(
		erased<EXPRESSION> const & field_1,
		std::vector<erased<IC>> const & field_2,
		std::vector<erased<IC>> const & field_3,
		erased<EXPRESSION> const & field_4
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4) {}

	static SYMMETRIC_DIFFERENCE build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_SYMMETRIC_DIFFERENCE_HPP
