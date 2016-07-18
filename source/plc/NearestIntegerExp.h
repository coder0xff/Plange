#ifndef NEAREST_INTEGER_EXP_H
#define NEAREST_INTEGER_EXP_H

#include "ParentExp.h"

class NearestIntegerExp :
	public ParentExp
{
public:
	NearestIntegerExp(Expression const & subExpression);
	~NearestIntegerExp();
	value evaluate() const override;
};

#endif //NEAREST_INTEGER_EXP_H
