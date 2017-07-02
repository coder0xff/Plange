// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_LESSER_CHAIN_LOOP_HPP
#define INCLUDED_LESSER_CHAIN_LOOP_HPP
struct LESSER_CHAIN_LOOP {
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>,
		std::std::integral_constant<int, 2>,
		std::std::integral_constant<int, 3>
	> field_1;
	std::vector<IC> field_2;
	EXPRESSION field_3;
	std::optional<std::tuple<
		std::vector<IC>,
		LESSER_CHAIN_LOOP
	>> field_4;
};

#endif //INCLUDED_LESSER_CHAIN_LOOP_HPP