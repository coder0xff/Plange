#ifndef DELTA_EXP_HPP
#define DELTA_EXP_HPP

#include "Expression.hpp"
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
	value evaluate(execution_context &exc) const override;
};

#endif //DELTA_EXP_HPP
