#ifndef NEAREST_INTEGER_EXP_H
#define NEAREST_INTEGER_EXP_H

#include "Expression.h"
class NearestIntegerExp :
	public Expression
{
public:
	NearestIntegerExp(Expression const & subExpression);
	~NearestIntegerExp();
	Expression sub_expression;
};

#endif //NEAREST_INTEGER_EXP_H
