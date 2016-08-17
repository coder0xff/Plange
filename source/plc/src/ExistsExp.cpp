#include "ExistsExp.hpp"
#include "value.hpp"



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

value ExistsExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
