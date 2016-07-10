#pragma once
#include "Expression.h"
class BoolExp :
	public Expression
{
public:
	BoolExp(bool value);
	~BoolExp();
	bool value;
};

