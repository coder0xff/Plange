#ifndef VECTOR_NORM_EXP_HPP
#define VECTOR_NORM_EXP_HPP

#include "ParentExp.hpp"

class VectorNormExp :
	public ParentExp	
{
public:
	VectorNormExp(Expression const & subExpression);
	~VectorNormExp();
	value evaluate() const override;
};

#endif //VECTOR_NORM_EXP_HPP
