#ifndef RADICAL_EXP_HPP
#define RADICAL_EXP_HPP

#include "UnaryOpExp.hpp"
#include <memory>

class RadicalExp :
	public UnaryOpExp
{
public:
	RadicalExp(Expression const & subExpression);
	~RadicalExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate(execution_context &exc) const override;
};

#endif //RADICAL_EXP_HPP
