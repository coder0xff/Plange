// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_UNIT_MULTIPLICATION_HPP
#define INCLUDED_UNIT_MULTIPLICATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct DIMENSION;

struct UNIT_MULTIPLICATION {
	erased<DIMENSION> field_1;
	erased<DIMENSION> field_2;


	UNIT_MULTIPLICATION(
		erased<DIMENSION> const & field_1,
		erased<DIMENSION> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static UNIT_MULTIPLICATION build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_UNIT_MULTIPLICATION_HPP
