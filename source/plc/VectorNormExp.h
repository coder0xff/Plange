#ifndef VECTOR_NORM_EXP_H
#define VECTOR_NORM_EXP_H

#include "ParentExp.h"

class VectorNormExp :
	public ParentExp	
{
public:
	VectorNormExp(Expression const & subExpression);
	~VectorNormExp();
	value evaluate() const override;
};

#endif //VECTOR_NORM_EXP_H
