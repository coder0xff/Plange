// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_GREATER_CHAIN_LOOP_HPP
#define INCLUDED_GREATER_CHAIN_LOOP_HPP
struct GREATER_CHAIN_LOOP {
	EXPRESSION EXPRESSION;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>,
		std::std::integral_constant<int, 2>,
		std::std::integral_constant<int, 3>
	> field_1;
	std::vector<IC> field_2;
	std::optional<std::tuple<
		std::vector<IC>,
		GREATER_CHAIN_LOOP
	>> field_3;
};

#endif //INCLUDED_GREATER_CHAIN_LOOP_HPP