#ifndef DIMENSIONAL_NUMBER_EXP_HPP
#define DIMENSIONAL_NUMBER_EXP_HPP

#include "Expression.h"
class DimensionalNumberExp :
	public Expression
{
public:
	DimensionalNumberExp();
	~DimensionalNumberExp();
	value evaluate() const override;
};

#endif //DIMENSIONAL_NUMBER_EXP_HPP
