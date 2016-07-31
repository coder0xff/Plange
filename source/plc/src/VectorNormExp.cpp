#include "VectorNormExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



VectorNormExp::VectorNormExp(Expression const & subExpression) : ParentExp(subExpression)
{
}


VectorNormExp::~VectorNormExp()
{
}

value VectorNormExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
