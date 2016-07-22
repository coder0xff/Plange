#ifndef CEILING_EXP_H
#define CEILING_EXP_H

#include "ParentExp.h"

class CeilingExp :
	public ParentExp
{
public:
	CeilingExp(Expression const & subExpression);
	~CeilingExp();
	value evaluate() const override;
};

#endif //CEILING_EXP_H
