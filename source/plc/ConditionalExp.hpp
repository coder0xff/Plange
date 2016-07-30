#ifndef CONDITIONAL_EXP_HPP
#define CONDITIONAL_EXP_HPP

#include "Expression.h"
#include <memory>

class ConditionalExp :
	public Expression
{
public:
	ConditionalExp();
	ConditionalExp(ConditionalExp const & other);
	~ConditionalExp();
	std::unique_ptr<Expression> condition;
	std::unique_ptr<Expression> true_case;
	std::unique_ptr<Expression> false_case;
	value evaluate() const override;
};

#endif //CONDITIONAL_EXP_HPP
