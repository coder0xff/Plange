#include "RadicalExp.hpp"
#include "value.hpp"



RadicalExp::RadicalExp(Expression const & subExpression) : UnaryOpExp(subExpression) {}


RadicalExp::~RadicalExp()
{
}

std::u32string RadicalExp::get_name() const
{
	return U"√";
}

bool RadicalExp::get_postfix() const
{
	return false;
}

value RadicalExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
