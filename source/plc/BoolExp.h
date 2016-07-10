#ifndef BOOL_EXP_H
#define BOOL_EXP_H

#include "Expression.h"
class BoolExp :
	public Expression
{
public:
	BoolExp(bool value);
	~BoolExp();
	bool value;
};

#endif //BOOL_EXP_H
