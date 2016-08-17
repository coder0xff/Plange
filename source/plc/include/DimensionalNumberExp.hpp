#ifndef DIMENSIONAL_NUMBER_EXP_HPP
#define DIMENSIONAL_NUMBER_EXP_HPP

#include "Expression.hpp"
class DimensionalNumberExp :
	public Expression
{
public:
	DimensionalNumberExp();
	~DimensionalNumberExp();
	value evaluate(execution_context &exc) const override;
};

#endif //DIMENSIONAL_NUMBER_EXP_HPP
