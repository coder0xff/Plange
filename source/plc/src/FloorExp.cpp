#include "FloorExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



FloorExp::FloorExp(Expression const & subExpression) : ParentExp(subExpression) {}


FloorExp::~FloorExp()
{
}

value FloorExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
