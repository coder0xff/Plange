#ifndef MAGNITUDE_EXP_HPP
#define MAGNITUDE_EXP_HPP

#include "ParentExp.hpp"

class MagnitudeExp :
	public ParentExp
{
public:
	MagnitudeExp(Expression const & subExpression);
	~MagnitudeExp();
	value evaluate(execution_context &exc) const override;
};

#endif //MAGNITUDE_EXP_HPP