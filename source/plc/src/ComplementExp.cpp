#include "ComplementExp.hpp"
#include "value.hpp"



ComplementExp::ComplementExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


ComplementExp::~ComplementExp()
{
}

std::u32string ComplementExp::get_name() const
{
	return U"ᶜ";
}

bool ComplementExp::get_postfix() const
{
	return true;
}

value ComplementExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
