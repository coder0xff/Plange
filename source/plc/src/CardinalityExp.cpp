#include "CardinalityExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



CardinalityExp::CardinalityExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


CardinalityExp::~CardinalityExp()
{
}

std::u32string CardinalityExp::get_name() const
{
	return U"#";
}

bool CardinalityExp::get_postfix() const
{
	return false;
}

value CardinalityExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
