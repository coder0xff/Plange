#ifndef INVOCATION_EXP_HPP
#define INVOCATION_EXP_HPP

#include "Expression.h"
#include <vector>
#include <memory>

class InvocationExp :
	public Expression
{
public:
	InvocationExp();
	InvocationExp(InvocationExp const & other);
	~InvocationExp();
	std::unique_ptr<Expression> function;
	std::vector<std::unique_ptr<Expression>> arguments;
	value evaluate() const override;
};

#endif //INVOCATION_EXP_HPP
