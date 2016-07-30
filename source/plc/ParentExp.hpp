#ifndef PARENT_EXP_HPP
#define PARENT_EXP_HPP
#include "Expression.h"

class ParentExp : public Expression {
public:
	ParentExp(Expression const & subExpression);
	ParentExp(ParentExp const & other);
	~ParentExp() = default;
	std::unique_ptr<Expression> sub_expression;
	virtual value evaluate() const = 0;
};

#endif //PARENT_EXP_HPP
