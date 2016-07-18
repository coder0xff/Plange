#ifndef RANGE_EXP_H
#define RANGE_EXP_H

#include "Expression.h"
class RangeExp :
	public Expression
{
public:
	RangeExp();
	~RangeExp();
	value evaluate() const override;
};

#endif //RANGE_EXP_H
