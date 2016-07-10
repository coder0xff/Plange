#ifndef FLOOR_EXP_H
#define FLOOR_EXP_H

#include "Expression.h"
class FloorExp :
	public Expression
{
public:
	FloorExp(Expression const & subExpression);
	~FloorExp();
	Expression sub_expression;
};

#endif //FLOOR_EXP_H
