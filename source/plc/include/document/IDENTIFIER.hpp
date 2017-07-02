// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_IDENTIFIER_HPP
#define INCLUDED_IDENTIFIER_HPP
struct IDENTIFIER {
	std::variant<
		letter,
		std::std::integral_constant<int, 1>
	> field_1;
	std::vector<std::variant<
		letter,
		number,
		std::std::integral_constant<int, 2>
	>> field_2;
};

#endif //INCLUDED_IDENTIFIER_HPP