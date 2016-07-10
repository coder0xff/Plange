#pragma once
#include "Expression.h"
#include <string>

class UnaryOpExp :
	public Expression
{
public:
	UnaryOpExp();
	~UnaryOpExp();
	virtual std::u32string name() const = 0;
	Expression sub_expression;
};

