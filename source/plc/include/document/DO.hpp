// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DO_HPP
#define INCLUDED_DO_HPP

struct EXPRESSION;
struct IC;
struct PARENTHETICAL;

struct DO {
	erased<EXPRESSION> EXPRESSION;
	std::vector<erased<IC>> field_1;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>,
		std::vector<erased<IC>>,
		erased<PARENTHETICAL>
	>> field_2;
};



#endif //INCLUDED_DO_HPP
