// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALLOCATION_HPP
#define INCLUDED_ALLOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct IC;
struct PARENTHETICAL_INVOCATION;

struct ALLOCATION {
	std::vector<erased<IC>> field_1;
	erased<PARENTHETICAL_INVOCATION> field_2;


	ALLOCATION(
		std::vector<erased<IC>> const & field_1,
		erased<PARENTHETICAL_INVOCATION> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static ALLOCATION build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ALLOCATION_HPP
