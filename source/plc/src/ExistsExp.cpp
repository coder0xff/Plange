#include "ExistsExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value ExistsExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
