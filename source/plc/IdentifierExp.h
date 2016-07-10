#pragma once
#include "Expression.h"
#include "value.h"

class IdentifierExp :
	public Expression
{
public:
	IdentifierExp();
	~IdentifierExp();
	value value;
};

