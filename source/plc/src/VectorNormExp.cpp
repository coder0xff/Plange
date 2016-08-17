#include "VectorNormExp.hpp"
#include "value.hpp"



VectorNormExp::VectorNormExp(Expression const & subExpression) : ParentExp(subExpression)
{
}


VectorNormExp::~VectorNormExp()
{
}

value VectorNormExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
