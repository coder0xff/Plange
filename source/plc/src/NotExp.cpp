#include "NotExp.hpp"
#include "value.hpp"



NotExp::NotExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


NotExp::~NotExp()
{
}

std::u32string NotExp::get_name() const
{
	return U"¬";
}

bool NotExp::get_postfix() const
{
	return false;
}

value NotExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
