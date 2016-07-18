#ifndef CAST_EXP_H
#define CAST_EXP_H

#include "ParentExp.h"

class CastExp :
	public ParentExp
{
public:
	CastExp(Expression const & subExpression, Expression const & targetType);
	CastExp(CastExp const & other);
	~CastExp();
	std::unique_ptr<Expression> target_type;
	value evaluate() const override;
};

#endif //CAST_EXP_H