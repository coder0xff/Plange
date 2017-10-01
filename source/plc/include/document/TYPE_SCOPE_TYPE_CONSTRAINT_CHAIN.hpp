// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct DEFINITION;
struct IC;
struct TYPE_SCOPE_ASSIGNMENT_CHAIN;
struct TYPE_SCOPE_DECLARATION;
struct TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN;
struct XML_DOC_STRING;

struct TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	std::variant<
		erased<TYPE_SCOPE_DECLARATION>,
		erased<TYPE_SCOPE_ASSIGNMENT_CHAIN>,
		erased<DEFINITION>
	> field_2;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN>
	>> field_3;


	TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		std::variant<
			erased<TYPE_SCOPE_DECLARATION>,
			erased<TYPE_SCOPE_ASSIGNMENT_CHAIN>,
			erased<DEFINITION>
		> const & field_2,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN>
		>> const & field_3
	) : field_1(field_1), field_2(field_2), field_3(field_3) {}

	static TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
