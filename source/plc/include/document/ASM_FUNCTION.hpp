// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_FUNCTION_HPP
#define INCLUDED_ASM_FUNCTION_HPP
struct ASM_FUNCTION {
	std::optional<std::tuple<
		std::vector<IC>,
		std::optional<std::tuple<
			PARAMETER,
			std::vector<std::tuple<
				std::vector<IC>,
				std::vector<IC>,
				PARAMETER
			>>,
			std::vector<IC>
		>>,
		std::vector<IC>
	>> field_1;
	std::optional<FUNCTION_MODIFIER_0> field_2;
	std::vector<IC> field_3;
	ASM_SCOPE field_4;
};

#endif //INCLUDED_ASM_FUNCTION_HPP