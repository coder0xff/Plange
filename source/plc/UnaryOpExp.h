#ifndef UNARY_OP_EXP_H
#define UNARY_OP_EXP_H

#include "Expression.h"
#include <string>
#include <memory>

class UnaryOpExp :
	public Expression
{
public:
	explicit UnaryOpExp(Expression const & subExpression);
	UnaryOpExp(UnaryOpExp const & other);
	~UnaryOpExp();
	std::unique_ptr<Expression> sub_expression;
	virtual std::u32string get_name() const = 0;
	virtual bool get_postfix() const = 0;
	virtual value evaluate() const = 0;
};

#endif //UNARY_OP_EXP_H
