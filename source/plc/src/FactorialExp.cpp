#include "FactorialExp.hpp"



FactorialExp::FactorialExp(Expression const & subExpression) : UnaryOpExp(subExpression) {}


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
