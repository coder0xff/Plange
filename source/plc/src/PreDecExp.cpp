#include "PreDecExp.hpp"
#include "value.hpp"



PreDecExp::PreDecExp(Expression const & subExpression) : UnaryOpExp(subExpression)
{
}


PreDecExp::~PreDecExp()
{
}

std::u32string PreDecExp::get_name() const
{
	return U"--";
}

bool PreDecExp::get_postfix() const
{
	return false;
}

value PreDecExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
