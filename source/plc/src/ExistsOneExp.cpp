#include "ExistsOneExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ExistsOneExp::ExistsOneExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


ExistsOneExp::~ExistsOneExp()
{
}

std::u32string ExistsOneExp::get_name() const
{
	return U"∃!";
}

bool ExistsOneExp::get_postfix() const
{
	return false;
}

value ExistsOneExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
