#include "NegationExp.hpp"



NegationExp::NegationExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


NegationExp::~NegationExp()
{
}

std::u32string NegationExp::get_name() const
{
	return U"-";
}

bool NegationExp::get_postfix() const
{
	return false;
}
