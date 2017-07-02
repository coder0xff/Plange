// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP
#define INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP

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
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_5;
	std::vector<erased<IC>> field_6;
	std::variant<
		erased<EXPRESSION>,
		erased<ASSIGNMENT_CHAIN>
	> field_7;
};



#endif //INCLUDED_TYPE_SCOPE_ASSIGNMENT_CHAIN_HPP
