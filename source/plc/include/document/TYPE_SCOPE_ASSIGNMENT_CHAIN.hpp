// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP
#define INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP

#include <optional>
#include <variant>
#include <vector>
#include "erased.hpp"
#include "parlex/details/abstract_syntax_tree.hpp"

#include "_plange_literals.hpp"

namespace plc {

struct ASSIGNMENT_CHAIN;
struct EXPRESSION;
struct IC;
struct IDENTIFIER;
struct MEMBER_OFFSET;
struct XML_DOC_STRING;

struct TYPE_SCOPE_ASSIGNMENT_CHAIN {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> field_2;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<MEMBER_OFFSET>
	>> field_3;
	std::vector<erased<IC>> field_4;
	std::variant<
		literal_0xE20x860x90_t,
		literal_0x3C0x2D_t
	> field_5;
	std::vector<erased<IC>> field_6;
	std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	> field_7;


	TYPE_SCOPE_ASSIGNMENT_CHAIN(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		erased<IDENTIFIER> const & field_2,
		std::optional<std::tuple<
			std::vector<erased<IC>>,
			erased<MEMBER_OFFSET>
		>> const & field_3,
		std::vector<erased<IC>> const & field_4,
		std::variant<
			literal_0xE20x860x90_t,
			literal_0x3C0x2D_t
		> const & field_5,
		std::vector<erased<IC>> const & field_6,
		std::variant<
			erased<EXPRESSION>,
			erased<ASSIGNMENT_CHAIN>
		> const & field_7
	) : field_1(field_1), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5), field_6(field_6), field_7(field_7) {}

	static TYPE_SCOPE_ASSIGNMENT_CHAIN build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP
