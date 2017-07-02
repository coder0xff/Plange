// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_NON_NEG_INTEGER_HPP
#define INCLUDED_NON_NEG_INTEGER_HPP
typedef std::variant<
	std::tuple<
		NON_ZERO_DECIMAL_DIGIT,
		std::vector<decimal_digit>
	>,
	std::std::integral_constant<int, 1>
> NON_NEG_INTEGER;#endif //INCLUDED_NON_NEG_INTEGER_HPP