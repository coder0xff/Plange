#pragma once
#include "Expression.h"
#include <string>

class StringExp :
	public Expression
{
public:
	StringExp(std::string const & value);
	~StringExp();
	std::string value;
};

