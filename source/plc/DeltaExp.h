#ifndef DELTA_EXP_H
#define DELTA_EXP_H

#include "Expression.h"
class DeltaExp :
	public Expression
{
public:
	DeltaExp(int const rank, Expression const & subExpression);
	~DeltaExp();
	int rank;
	Expression sub_expression;
};

#endif //DELTA_EXP_H
