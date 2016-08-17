#include "CardinalityExp.hpp"
#include "value.hpp"



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

value CardinalityExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
