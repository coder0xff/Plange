#ifndef ASM_FUNCTION_EXP_HPP
#define ASM_FUNCTION_EXP_HPP

#include "Expression.hpp"

class AsmFunctionExp :
	public Expression {
public:
	AsmFunctionExp();
	~AsmFunctionExp();
	value evaluate() const override;
};

#endif //ASM_FUNCTION_EXP_HPP
