// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASSIGNMENT_CHAIN;
struct DECLARATION;
struct DEFINITION;
struct IC;
struct TYPE_CONSTRAINT_CHAIN;

struct TYPE_CONSTRAINT_CHAIN {
	std::variant<
		erased<DECLARATION>,
		erased<ASSIGNMENT_CHAIN>,
		erased<DEFINITION>
	> field_1;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<TYPE_CONSTRAINT_CHAIN>
	>> field_2;


	TYPE_CONSTRAINT_CHAIN(
		std::variant<
			erased<DECLARATION>,
			erased<ASSIGNMENT_CHAIN>,
			erased<DEFINITION>
		> const & field_1,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<TYPE_CONSTRAINT_CHAIN>
		>> const & field_2
	) : field_1(field_1), field_2(field_2) {}

	static TYPE_CONSTRAINT_CHAIN build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
