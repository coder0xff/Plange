#ifndef NEGATION_EXP_HPP
#define NEGATION_EXP_HPP

#include "UnaryOpExp.hpp"
class NegationExp :
	public UnaryOpExp
{
public:
	NegationExp(Expression const & subExpression);
	~NegationExp();

	std::u32string get_name() const override;
	bool get_postfix() const override;
	value evaluate() const override;
};

#endif //NEGATION_EXP_HPP
