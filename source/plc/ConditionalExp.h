#pragma once
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

