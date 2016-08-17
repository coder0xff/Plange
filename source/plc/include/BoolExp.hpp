#ifndef BOOL_EXP_HPP
#define BOOL_EXP_HPP

#include "Expression.hpp"

class BoolExp :
	public Expression
{
public:
	BoolExp(bool value);
	~BoolExp();
	bool val;
	value evaluate(execution_context &exc) const override;
};

#endif //BOOL_EXP_HPP
