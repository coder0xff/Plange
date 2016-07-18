#ifndef DIMENSIONAL_NUMBER_EXP_H
#define DIMENSIONAL_NUMBER_EXP_H

#include "Expression.h"
class DimensionalNumberExp :
	public Expression
{
public:
	DimensionalNumberExp();
	~DimensionalNumberExp();
	value evaluate() const override;
};

#endif //DIMENSIONAL_NUMBER_EXP_H
