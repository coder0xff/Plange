// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_RANGE_HPP
#define INCLUDED_RANGE_HPP

struct EXPRESSION;
struct IC;

typedef std::variant<
	std::tuple<
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>
	>,
	std::tuple<
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::vector<erased<IC>>
	>,
	std::tuple<
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::vector<erased<IC>>,
		erased<EXPRESSION>,
		std::vector<erased<IC>>,
		std::variant<
			std::std::integral_constant<int, 0>,
			std::std::integral_constant<int, 1>
		>
	>
> RANGE;

#endif //INCLUDED_RANGE_HPP
