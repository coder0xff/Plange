#pragma once
#include "Expression.h"
#include <vector>

class ListExp :
	public Expression
{
public:
	ListExp();
	~ListExp();
	std::vector<Expression> elements;
};

