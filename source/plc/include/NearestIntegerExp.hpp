#ifndef NEAREST_INTEGER_EXP_HPP
#define NEAREST_INTEGER_EXP_HPP

#include "ParentExp.hpp"

class NearestIntegerExp :
	public ParentExp
{
public:
	NearestIntegerExp(Expression const & subExpression);
	~NearestIntegerExp();
	value evaluate(execution_context &exc) const override;
};

#endif //NEAREST_INTEGER_EXP_HPP
