#ifndef RADICAL_EXP_H
#define RADICAL_EXP_H

#include "UnaryOpExp.h"

class RadicalExp :
	public UnaryOpExp
{
public:
	RadicalExp(Expression const & subExpression);
	~RadicalExp();
	Expression sub_expression;

	std::u32string get_name() const override;
	bool get_postfix() const override;

};

#endif //RADICAL_EXP_H
