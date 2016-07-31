#include "PostDecExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value PostDecExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
