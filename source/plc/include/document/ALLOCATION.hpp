// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALLOCATION_HPP
#define INCLUDED_ALLOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct PARENTHETICAL_INVOCATION;

struct ALLOCATION {
	std::vector<erased<IC>> field_1;
	erased<PARENTHETICAL_INVOCATION> field_2;


	explicit ALLOCATION(
		std::vector<erased<IC>> && field_1,
		erased<PARENTHETICAL_INVOCATION> && field_2
	) : field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ALLOCATION(ALLOCATION const & other) = default;
	ALLOCATION(ALLOCATION && move) = default;

	static ALLOCATION build(parlex::details::behavior::node const & b, parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ALLOCATION_HPP
