#include "PostDecExp.hpp"
#include "value.hpp"



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

value PostDecExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
