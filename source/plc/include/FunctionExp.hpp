#ifndef FUNCTION_EXP_HPP
#define FUNCTION_EXP_HPP

#include "Expression.hpp"
class FunctionExp :
	public Expression
{
public:
	FunctionExp();
	~FunctionExp();
	value evaluate() const override;
};

#endif //FUNCTION_EXP_HPP
