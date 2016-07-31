#include "ParentheticalExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ParentheticalExp::ParentheticalExp(Expression const & subExpression) : ParentExp(subExpression) {}


ParentheticalExp::~ParentheticalExp()
{
}

value ParentheticalExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
