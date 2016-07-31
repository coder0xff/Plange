#ifndef RANGE_EXP_HPP
#define RANGE_EXP_HPP

#include "Expression.hpp"
class RangeExp :
	public Expression
{
public:
	RangeExp();
	~RangeExp();
	value evaluate() const override;
};

#endif //RANGE_EXP_HPP
