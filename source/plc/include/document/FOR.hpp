// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FOR_HPP
#define INCLUDED_FOR_HPP

struct ASSIGNMENT_CHAIN;
struct EXPRESSION;
struct IC;
struct STATEMENT_SCOPE;

struct FOR {
	erased<EXPRESSION> condition;
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	std::vector<erased<IC>> field_4;
	std::vector<erased<IC>> field_5;
	erased<EXPRESSION> field_6;
	std::optional<std::tuple<
		erased<STATEMENT_SCOPE>,
		std::vector<erased<IC>>
	>> initializer;
	std::optional<std::tuple<
		erased<ASSIGNMENT_CHAIN>,
		std::vector<std::tuple<
			std::vector<erased<IC>>,
			std::vector<erased<IC>>,
			erased<ASSIGNMENT_CHAIN>
		>>,
		std::vector<erased<IC>>
	>> step;
};



#endif //INCLUDED_FOR_HPP
