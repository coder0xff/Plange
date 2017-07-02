// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LOOP_HPP
#define INCLUDED_LOOP_HPP

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct LOOP {
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<PARENTHETICAL> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;
};



#endif //INCLUDED_LOOP_HPP
