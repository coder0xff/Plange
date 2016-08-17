#include "MagnitudeExp.hpp"
#include "value.hpp"



MagnitudeExp::MagnitudeExp(Expression const & subExpression) : ParentExp(subExpression) {}


MagnitudeExp::~MagnitudeExp()
{
}

value MagnitudeExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
