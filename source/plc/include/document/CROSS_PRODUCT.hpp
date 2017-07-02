// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CROSS_PRODUCT_HPP
#define INCLUDED_CROSS_PRODUCT_HPP

struct EXPRESSION;
struct IC;

struct CROSS_PRODUCT {
	erased<EXPRESSION> field_1;
	std::vector<erased<IC>> field_2;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> field_5;
};



#endif //INCLUDED_CROSS_PRODUCT_HPP
