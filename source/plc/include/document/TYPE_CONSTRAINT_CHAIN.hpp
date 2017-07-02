// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
#define INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP

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
};



#endif //INCLUDED_TYPE_CONSTRAINT_CHAIN_HPP
