#ifndef IDENTIFIER_EXP_HPP
#define IDENTIFIER_EXP_HPP

#include "Expression.h"
#include "value.h"

class IdentifierExp :
	public Expression
{
public:
	IdentifierExp(value & val);
	~IdentifierExp();
	value val;
	value evaluate() const override;
};

#endif //IDENTIFIER_EXP_HPP
