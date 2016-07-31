#include "IdentifierExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



IdentifierExp::IdentifierExp(value & val) : val(val) {}


IdentifierExp::~IdentifierExp()
{
}

value IdentifierExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
