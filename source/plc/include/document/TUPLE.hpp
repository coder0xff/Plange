// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_TUPLE_HPP
#define INCLUDED_TUPLE_HPP

struct EXPRESSION;
struct IC;

struct TUPLE {
	std::vector<erased<IC>> field_1;
	erased<EXPRESSION> field_2;
	std::vector<std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>
	>> field_3;
	std::vector<erased<IC>> field_4;
};



#endif //INCLUDED_TUPLE_HPP
