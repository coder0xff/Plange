// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP

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
};



#endif //INCLUDED_TYPE_SCOPE_TYPE_CONSTRAINT_CHAIN_HPP
