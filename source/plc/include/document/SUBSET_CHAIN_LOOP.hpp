// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_SUBSET_CHAIN_LOOP_HPP
#define INCLUDED_SUBSET_CHAIN_LOOP_HPP

struct EXPRESSION;
struct IC;
struct SUBSET_CHAIN_LOOP;

struct SUBSET_CHAIN_LOOP {
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>,
		std::std::integral_constant<int, 2>,
		std::std::integral_constant<int, 3>,
		std::std::integral_constant<int, 4>
	> field_1;
	std::vector<erased<IC>> field_2;
	erased<EXPRESSION> field_3;
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		erased<SUBSET_CHAIN_LOOP>
	>> field_4;
};



#endif //INCLUDED_SUBSET_CHAIN_LOOP_HPP
