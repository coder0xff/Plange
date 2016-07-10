#ifndef MAGNITUDE_EXP_H
#define MAGNITUDE_EXP_H

#include "Expression.h"
class MagnitudeExp :
	public Expression
{
public:
	MagnitudeExp(Expression const & subExpression);
	~MagnitudeExp();
	Expression sub_expression;
};

#endif //MAGNITUDE_EXP_H