// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_FUNCTION_HPP
#define INCLUDED_ASM_FUNCTION_HPP

struct ASM_SCOPE;
struct FUNCTION_MODIFIER_0;
struct IC;
struct PARAMETER;

struct ASM_FUNCTION {
	std::optional<std::tuple<
		std::vector<erased<IC>>,
		std::optional<std::tuple<
			erased<PARAMETER>,
			std::vector<std::tuple<
				std::vector<erased<IC>>,
				std::vector<erased<IC>>,
				erased<PARAMETER>
			>>,
			std::vector<erased<IC>>
		>>,
		std::vector<erased<IC>>
	>> field_1;
	std::optional<erased<FUNCTION_MODIFIER_0>> field_2;
	std::vector<erased<IC>> field_3;
	erased<ASM_SCOPE> field_4;
};



#endif //INCLUDED_ASM_FUNCTION_HPP
