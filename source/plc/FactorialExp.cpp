#include "FactorialExp.h"



FactorialExp::FactorialExp(Expression const & subExpression) : sub_expression(subExpression) {}


FactorialExp::~FactorialExp()
{
}

std::u32string FactorialExp::get_name() const
{
	return U"!";
}

bool FactorialExp::get_postfix() const
{
	return true;
}
