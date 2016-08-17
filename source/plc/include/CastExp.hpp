#ifndef CAST_EXP_HPP
#define CAST_EXP_HPP

#include "ParentExp.hpp"

class CastExp :
	public ParentExp
{
public:
	CastExp(Expression const & subExpression, Expression const & targetType);
	CastExp(CastExp const & other);
	~CastExp();
	std::unique_ptr<Expression> target_type;
	value evaluate(execution_context &exc) const override;
};

#endif //CAST_EXP_HPP