#include "IdentifierExp.hpp"
#include "value.hpp"



IdentifierExp::IdentifierExp(value & val) : val(val) {}


IdentifierExp::~IdentifierExp()
{
}

value IdentifierExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
