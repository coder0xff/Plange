#include "CardinalityExp.h"



CardinalityExp::CardinalityExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


CardinalityExp::~CardinalityExp()
{
}

std::u32string CardinalityExp::get_name() const
{
	return U"#";
}

bool CardinalityExp::get_postfix() const
{
	return false;
}
