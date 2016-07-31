#ifndef CEILING_EXP_HPP
#define CEILING_EXP_HPP

#include "ParentExp.hpp"

class CeilingExp :
	public ParentExp
{
public:
	CeilingExp(Expression const & subExpression);
	~CeilingExp();
	value evaluate() const override;
};

#endif //CEILING_EXP_HPP
