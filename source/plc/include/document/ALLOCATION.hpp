// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALLOCATION_HPP
#define INCLUDED_ALLOCATION_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"
#include "parlex/details/document.hpp"

#include "plange_grammar.hpp"

namespace plc {

struct IC;
struct PARENTHETICAL_INVOCATION;

struct ALLOCATION {
	parlex::details::document::text<literal_alloc_t> dontCare0;
	
	std::vector<erased<IC>> field_1;
	
	erased<PARENTHETICAL_INVOCATION> field_2;
	


	explicit ALLOCATION(
		parlex::details::document::text<literal_alloc_t> && dontCare0, std::vector<erased<IC>> && field_1, erased<PARENTHETICAL_INVOCATION> && field_2) : dontCare0(std::move(dontCare0)), field_1(std::move(field_1)), field_2(std::move(field_2)) {}

	ALLOCATION(ALLOCATION const & other) = default;
	ALLOCATION(ALLOCATION && move) = default;

	static ALLOCATION build(parlex::details::ast_node const & n);
	static parlex::details::recognizer const & recognizer();

};


} // namespace plc



#endif //INCLUDED_ALLOCATION_HPP
