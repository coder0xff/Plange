#ifndef IDENTIFIER_EXP_H
#define IDENTIFIER_EXP_H

#include "Expression.h"
#include "value.h"

class IdentifierExp :
	public Expression
{
public:
	IdentifierExp(value & val);
	~IdentifierExp();
	value val;
};

#endif //IDENTIFIER_EXP_H
