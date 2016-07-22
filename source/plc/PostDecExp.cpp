#include "PostDecExp.h"



PostDecExp::PostDecExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


PostDecExp::~PostDecExp()
{
}

std::u32string PostDecExp::get_name() const
{
	return U"--";
}

bool PostDecExp::get_postfix() const
{
	return true;
}
