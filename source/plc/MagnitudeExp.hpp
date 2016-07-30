#ifndef MAGNITUDE_EXP_HPP
#define MAGNITUDE_EXP_HPP

#include "ParentExp.h"

class MagnitudeExp :
	public ParentExp
{
public:
	MagnitudeExp(Expression const & subExpression);
	~MagnitudeExp();
	value evaluate() const override;
};

#endif //MAGNITUDE_EXP_HPP