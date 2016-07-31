#include "NegationExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



NegationExp::NegationExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


NegationExp::~NegationExp()
{
}

std::u32string NegationExp::get_name() const
{
	return U"-";
}

bool NegationExp::get_postfix() const
{
	return false;
}

value NegationExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
