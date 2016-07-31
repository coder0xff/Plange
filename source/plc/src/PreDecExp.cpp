#include "PreDecExp.hpp"



PreDecExp::PreDecExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


PreDecExp::~PreDecExp()
{
}

std::u32string PreDecExp::get_name() const
{
	return U"--";
}

bool PreDecExp::get_postfix() const
{
	return false;
}
