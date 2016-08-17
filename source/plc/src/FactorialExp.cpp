#include "FactorialExp.hpp"
#include "value.hpp"



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

value FactorialExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
