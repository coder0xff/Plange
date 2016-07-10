#pragma once
#include "Expression.h"
#include <vector>

class ArrayExp :
	public Expression {
public:
	ArrayExp();
	~ArrayExp();
	std::vector<Expression> elements;
};
