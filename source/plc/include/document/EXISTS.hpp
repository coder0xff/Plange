// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_EXISTS_HPP
#define INCLUDED_EXISTS_HPP

struct EXPRESSION;
struct IC;

struct EXISTS {
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
};



#endif //INCLUDED_EXISTS_HPP
