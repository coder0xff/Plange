#ifndef DELTA_EXP_H
#define DELTA_EXP_H

#include "Expression.h"
#include <memory>

class DeltaExp :
	public Expression
{
public:
	DeltaExp(int const rank, Expression const & subExpression);
	DeltaExp(DeltaExp const & other);
	~DeltaExp();
	int rank;
	std::unique_ptr<Expression> sub_expression;
	value evaluate() const override;
};

#endif //DELTA_EXP_H
