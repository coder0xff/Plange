#ifndef FLOOR_EXP_HPP
#define FLOOR_EXP_HPP

#include "ParentExp.h"

class FloorExp :
	public ParentExp
{
public:
	FloorExp(Expression const & subExpression);
	~FloorExp();
	value evaluate() const override;
};

#endif //FLOOR_EXP_HPP
