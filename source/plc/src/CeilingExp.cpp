#include "CeilingExp.hpp"
#include "value.hpp"



CeilingExp::CeilingExp(Expression const & subExpression) : ParentExp(subExpression) {}

CeilingExp::~CeilingExp()
{
}

value CeilingExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
