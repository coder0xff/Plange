#ifndef IDENTIFIER_EXP_HPP
#define IDENTIFIER_EXP_HPP

#include "Expression.hpp"
#include "value.hpp"

class IdentifierExp :
	public Expression
{
public:
	IdentifierExp(value & val);
	~IdentifierExp();
	value val;
	value evaluate(execution_context &exc) const override;
};

#endif //IDENTIFIER_EXP_HPP
