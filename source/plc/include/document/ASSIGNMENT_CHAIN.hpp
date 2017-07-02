// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASSIGNMENT_CHAIN_HPP
#define INCLUDED_ASSIGNMENT_CHAIN_HPP
struct ASSIGNMENT_CHAIN {
	IDENTIFIER IDENTIFIER;
	std::optional<std::tuple<
		XML_DOC_STRING,
		std::vector<IC>
	>> field_1;
	std::vector<IC> field_2;
	std::variant<
		std::std::integral_constant<int, 0>,
		std::std::integral_constant<int, 1>
	> field_3;
	std::vector<IC> field_4;
	std::variant<
		EXPRESSION,
		ASSIGNMENT_CHAIN
	> field_5;
};

#endif //INCLUDED_ASSIGNMENT_CHAIN_HPP