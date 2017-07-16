// This file was generated using Parlex's cpp_generator

#ifndef INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP
#define INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP

#include <optional>
#include <variant>
#include <vector>

#include "erased.hpp"

struct ASM_IDENTIFIER;
struct ASM_PTR_ARITHMETIC_ATT_REG;
struct NON_FRACTIONAL;

typedef std::variant<
	std::tuple<
		erased<ASM_IDENTIFIER>,
		erased<NON_FRACTIONAL>
	>,
	std::tuple<
		erased<ASM_IDENTIFIER>,
		erased<NON_FRACTIONAL>,
		erased<ASM_PTR_ARITHMETIC_ATT_REG>
	>,
	std::tuple<
		erased<NON_FRACTIONAL>,
		erased<ASM_PTR_ARITHMETIC_ATT_REG>
	>
> ASM_PTR_ARITHMETIC_ATT;

#endif //INCLUDED_ASM_PTR_ARITHMETIC_ATT_HPP
