#ifndef INVOCATION_EXP_H
#define INVOCATION_EXP_H

#include "Expression.h"
#include <vector>

class InvocationExp :
	public Expression
{
public:
	InvocationExp();
	~InvocationExp();
	Expression function;
	std::vector<Expression> arguments;
};

#endif //INVOCATION_EXP_H
