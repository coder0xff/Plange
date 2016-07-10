#ifndef CONDITIONAL_EXP_H
#define CONDITIONAL_EXP_H

#include "Expression.h"
class ConditionalExp :
	public Expression
{
public:
	ConditionalExp();
	~ConditionalExp();
	Expression condition;
	Expression true_case;
	Expression false_case;
};

#endif //CONDITIONAL_EXP_H
