#include "PostIncExp.hpp"



PostIncExp::PostIncExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


PostIncExp::~PostIncExp()
{
}

std::u32string PostIncExp::get_name() const
{
	return U"++";
}

bool PostIncExp::get_postfix() const
{
	return true;
}
