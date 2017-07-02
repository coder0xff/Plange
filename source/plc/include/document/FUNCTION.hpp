// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_HPP
#define INCLUDED_FUNCTION_HPP

struct BLOCK;
struct FUNCTION_MODIFIER_0;
struct IC;
struct PARAMETER;

struct FUNCTION {
	erased<BLOCK> BLOCK;
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
	std::optional<std::tuple<
		erased<FUNCTION_MODIFIER_0>,
		std::vector<erased<IC>>
	>> field_2;
};



#endif //INCLUDED_FUNCTION_HPP
