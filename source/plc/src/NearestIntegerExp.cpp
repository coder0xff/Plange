#include "NearestIntegerExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



NearestIntegerExp::NearestIntegerExp(Expression const & subExpression) : ParentExp(subExpression) {}


NearestIntegerExp::~NearestIntegerExp()
{
}

value NearestIntegerExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
