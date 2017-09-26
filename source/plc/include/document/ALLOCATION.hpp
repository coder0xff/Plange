// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALLOCATION_HPP
#define INCLUDED_ALLOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/match.hpp"

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

	static std::optional<ALLOCATION> build(std::vector<parlex::details::match>::iterator & i);

};


} // namespace plc



#endif //INCLUDED_ALLOCATION_HPP
