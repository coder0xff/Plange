#ifndef FACTORIAL_EXP_HPP
#define FACTORIAL_EXP_HPP

#include "UnaryOpExp.hpp"
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

#endif //FACTORIAL_EXP_HPP
