#include "BoolExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



BoolExp::BoolExp(bool value) : val(value)
{
}


BoolExp::~BoolExp()
{
}

value BoolExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
