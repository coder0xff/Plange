#include "FloorExp.hpp"
#include "value.hpp"



FloorExp::FloorExp(Expression const & subExpression) : ParentExp(subExpression) {}


FloorExp::~FloorExp()
{
}

value FloorExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
