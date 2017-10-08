// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNIT_DIVISION_HPP
#define INCLUDED_UNIT_DIVISION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct DIMENSION;

struct UNIT_DIVISION {
	erased<DIMENSION> field_1;
	erased<DIMENSION> field_2;


	explicit UNIT_DIVISION(
		erased<DIMENSION> && field_1,
		erased<DIMENSION> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	UNIT_DIVISION(UNIT_DIVISION const & other) = default;
	UNIT_DIVISION(UNIT_DIVISION && move) = default;

	static UNIT_DIVISION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_UNIT_DIVISION_HPP
