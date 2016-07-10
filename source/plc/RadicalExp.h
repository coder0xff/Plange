#ifndef RADICAL_EXP
#define RADICAL_EXP

#include "UnaryOpExp.h"

class RadicalExp :
	public UnaryOpExp
{
public:
	RadicalExp(Expression const & subExpression);
	~RadicalExp();
	Expression sub_expression;
};

#endif //RADICAL_EXP
