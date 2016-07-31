#include "FactorialExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



FactorialExp::FactorialExp(Expression const & subExpression) : UnaryOpExp(subExpression) {}


FactorialExp::~FactorialExp()
{
}

std::u32string FactorialExp::get_name() const
{
	return U"!";
}

bool FactorialExp::get_postfix() const
{
	return true;
}

value FactorialExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
