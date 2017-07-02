// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_CONDITIONAL_HPP
#define INCLUDED_CONDITIONAL_HPP

struct EXPRESSION;
struct IC;

struct CONDITIONAL {
	erased<EXPRESSION> condition;
	erased<EXPRESSION> false_case;
	std::vector<erased<IC>> field_1;
	std::vector<erased<IC>> field_2;
	std::vector<erased<IC>> field_3;
	std::vector<erased<IC>> field_4;
	erased<EXPRESSION> true_case;
};



#endif //INCLUDED_CONDITIONAL_HPP
