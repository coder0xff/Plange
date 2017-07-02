// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_HPP
#define INCLUDED_FUNCTION_HPP
struct FUNCTION {
	BLOCK BLOCK;
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
	std::optional<std::tuple<
		FUNCTION_MODIFIER_0,
		std::vector<IC>
	>> field_2;
};

#endif //INCLUDED_FUNCTION_HPP