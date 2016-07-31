#include "PropertyExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



PropertyExp::PropertyExp()
{
}


PropertyExp::~PropertyExp()
{
}

value PropertyExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
