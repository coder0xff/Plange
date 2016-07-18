#ifndef PARENT_EXP_H
#define PARENT_EXP_H
#include "Expression.h"

class ParentExp : public Expression {
public:
	ParentExp(Expression const & subExpression);
	ParentExp(ParentExp const & other);
	~ParentExp() = default;
	std::unique_ptr<Expression> sub_expression;
	virtual value evaluate() const = 0;
};

#endif //PARENT_EXP_H
