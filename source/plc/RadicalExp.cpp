#include "RadicalExp.h"



RadicalExp::RadicalExp(Expression const & subExpression) : sub_expression(subExpression) {}


RadicalExp::~RadicalExp()
{
}

std::u32string RadicalExp::get_name() const
{
	return U"√";
}

bool RadicalExp::get_postfix() const
{
	return false;
}
