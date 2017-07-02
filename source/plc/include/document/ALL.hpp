// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ALL_HPP
#define INCLUDED_ALL_HPP

struct EXPRESSION;
struct IC;

struct ALL {
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
};



#endif //INCLUDED_ALL_HPP
