// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
#define INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP

struct FUNCTION_MODIFIER_4;
struct ICR;
struct PLATFORM;

struct FUNCTION_MODIFIER_PLATFORM {
	erased<PLATFORM> field_1;
	std::vector<std::tuple<
		erased<ICR>,
		erased<PLATFORM>
	>> field_2;
	std::optional<std::tuple<
		erased<ICR>,
		erased<FUNCTION_MODIFIER_4>
	>> field_3;
};



#endif //INCLUDED_FUNCTION_MODIFIER_PLATFORM_HPP
