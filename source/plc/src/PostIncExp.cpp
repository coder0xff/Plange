#include "PostIncExp.hpp"
#include "value.hpp"



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

value PostIncExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
