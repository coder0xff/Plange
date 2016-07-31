#include "RadicalExp.hpp"



RadicalExp::RadicalExp(Expression const & subExpression) : UnaryOpExp(subExpression) {}


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
