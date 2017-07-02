// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_STATEMENT_HPP
#define INCLUDED_ASM_STATEMENT_HPP
struct ASM_STATEMENT {
	ASM_OP field_1;
	std::optional<std::tuple<
		ICR,
		ASM_EXPRESSION,
		std::vector<std::tuple<
			std::vector<IC>,
			std::optional<std::tuple<
				std::vector<IC>,
				ASM_EXPRESSION
			>>
		>>
	>> field_2;
	std::vector<IC> field_3;
};

#endif //INCLUDED_ASM_STATEMENT_HPP