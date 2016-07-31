#include "CeilingExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



CeilingExp::CeilingExp(Expression const & subExpression) : ParentExp(subExpression) {}

CeilingExp::~CeilingExp()
{
}

value CeilingExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
