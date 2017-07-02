// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DO_HPP
#define INCLUDED_DO_HPP
struct DO {
	EXPRESSION EXPRESSION;
	std::vector<IC> field_1;
	std::optional<std::tuple<
		std::vector<IC>,
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>,
		std::vector<IC>,
		PARENTHETICAL
	>> field_2;
};

#endif //INCLUDED_DO_HPP