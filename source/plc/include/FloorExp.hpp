#ifndef FLOOR_EXP_HPP
#define FLOOR_EXP_HPP

#include "ParentExp.hpp"

class FloorExp :
	public ParentExp
{
public:
	FloorExp(Expression const & subExpression);
	~FloorExp();
	value evaluate(execution_context &exc) const override;
};

#endif //FLOOR_EXP_HPP
