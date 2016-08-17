#include "NearestIntegerExp.hpp"
#include "value.hpp"



NearestIntegerExp::NearestIntegerExp(Expression const & subExpression) : ParentExp(subExpression) {}


NearestIntegerExp::~NearestIntegerExp()
{
}

value NearestIntegerExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
