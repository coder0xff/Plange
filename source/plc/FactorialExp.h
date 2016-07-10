#ifndef FACTORIAL_EXP_H
#define FACTORIAL_EXP_H

#include "UnaryOpExp.h"

class FactorialExp :
	public UnaryOpExp
{
public:
	FactorialExp(Expression const & subExpression);
	~FactorialExp();
	Expression sub_expression;

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //FACTORIAL_EXP_H
