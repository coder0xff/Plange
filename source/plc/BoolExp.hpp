#ifndef BOOL_EXP_HPP
#define BOOL_EXP_HPP

#include "Expression.h"

class BoolExp :
	public Expression
{
public:
	BoolExp(bool value);
	~BoolExp();
	bool val;
	value evaluate() const override;
};

#endif //BOOL_EXP_HPP
