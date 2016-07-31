#include "AllExp.hpp"



AllExp::AllExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


AllExp::~AllExp()
{
}

std::u32string AllExp::get_name() const
{
	return U"∀";
}

bool AllExp::get_postfix() const
{
	return false;
}
