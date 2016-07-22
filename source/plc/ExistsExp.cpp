#include "ExistsExp.h"



ExistsExp::ExistsExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


ExistsExp::~ExistsExp()
{
}

std::u32string ExistsExp::get_name() const
{
	return U"∃";
}

bool ExistsExp::get_postfix() const
{
	return false;
}
