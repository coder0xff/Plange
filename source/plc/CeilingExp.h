#ifndef CEILING_EXP_H
#define CEILING_EXP_H

#include "Expression.h"

class CeilingExp :
	public Expression
{
public:
	CeilingExp(Expression const & subExpression);
	~CeilingExp();
	Expression sub_expression;
};

#endif //CEILING_EXP_H
