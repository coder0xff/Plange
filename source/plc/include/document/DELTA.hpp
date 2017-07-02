// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_DELTA_HPP
#define INCLUDED_DELTA_HPP
struct DELTA {
	EXPRESSION EXPRESSION;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_1;
	std::optional<std::tuple<
		WHOLE_NUMBER
	>> field_2;
};

#endif //INCLUDED_DELTA_HPP