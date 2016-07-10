#ifndef FACTORIAL_EXP_H
#define FACTORIAL_EXP_H

#include "Expression.h"
class FactorialExp :
	public Expression
{
public:
	FactorialExp(Expression const & subExpression);
	~FactorialExp();
	Expression sub_expression;
};

#endif //FACTORIAL_EXP_H
