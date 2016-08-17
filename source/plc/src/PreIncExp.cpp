#include "PreIncExp.hpp"
#include "value.hpp"



PreIncExp::PreIncExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


PreIncExp::~PreIncExp()
{
}

std::u32string PreIncExp::get_name() const
{
	return U"++";
}

bool PreIncExp::get_postfix() const
{
	return false;
}

value PreIncExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
