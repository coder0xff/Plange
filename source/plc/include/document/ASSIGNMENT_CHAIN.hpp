// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASSIGNMENT_CHAIN_HPP
#define INCLUDED_ASSIGNMENT_CHAIN_HPP

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
struct XML_DOC_STRING;

struct ASSIGNMENT_CHAIN {
	std::optional<std::tuple<
		erased<XML_DOC_STRING>,
		std::vector<erased<IC>>
	>> field_1;
	erased<IDENTIFIER> identifier;
	std::vector<erased<IC>> field_2;
	std::variant<
		literal_0xE20x860x90_t,
		literal_0x3C0x2D_t
	> field_3;
	std::vector<erased<IC>> field_4;
	std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	> field_5;


	ASSIGNMENT_CHAIN(
		std::optional<std::tuple<
			erased<XML_DOC_STRING>,
			std::vector<erased<IC>>
		>> const & field_1,
		erased<IDENTIFIER> const & identifier,
		std::vector<erased<IC>> const & field_2,
		std::variant<
			literal_0xE20x860x90_t,
			literal_0x3C0x2D_t
		> const & field_3,
		std::vector<erased<IC>> const & field_4,
		std::variant<
			erased<EXPRESSION>,
			erased<ASSIGNMENT_CHAIN>
		> const & field_5
	) : field_1(field_1), identifier(identifier), field_2(field_2), field_3(field_3), field_4(field_4), field_5(field_5) {}

	static ASSIGNMENT_CHAIN build(parlex::details::ast_node const & n);

};


} // namespace plc



#endif //INCLUDED_ASSIGNMENT_CHAIN_HPP
