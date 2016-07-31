#include "MagnitudeExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



MagnitudeExp::MagnitudeExp(Expression const & subExpression) : ParentExp(subExpression) {}


MagnitudeExp::~MagnitudeExp()
{
}

value MagnitudeExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
