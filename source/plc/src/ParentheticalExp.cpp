#include "ParentheticalExp.hpp"
#include "value.hpp"



ParentheticalExp::ParentheticalExp(Expression const & subExpression) : ParentExp(subExpression) {}


ParentheticalExp::~ParentheticalExp()
{
}

value ParentheticalExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
