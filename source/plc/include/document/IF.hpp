// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IF_HPP
#define INCLUDED_IF_HPP

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct IF {
	erased<PARENTHETICAL> condition;
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<PARENTHETICAL>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_3;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_4;
	erased<EXPRESSION> invoke;
};



#endif //INCLUDED_IF_HPP
