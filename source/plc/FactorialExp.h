#ifndef FACTORIAL_EXP_H
#define FACTORIAL_EXP_H

#include "UnaryOpExp.h"
#include <memory>

class FactorialExp :
	public UnaryOpExp
{
public:
	FactorialExp(Expression const & subExpression);
	~FactorialExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //FACTORIAL_EXP_H
