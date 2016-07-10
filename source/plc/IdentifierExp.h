#ifndef IDENTIFIER_EXP_H
#define IDENTIFIER_EXP_H

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

#endif //IDENTIFIER_EXP_H
