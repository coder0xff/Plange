#include "PreIncExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value PreIncExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
