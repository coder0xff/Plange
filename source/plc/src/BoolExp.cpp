#include "BoolExp.hpp"
#include "value.hpp"



BoolExp::BoolExp(bool value) : val(value)
{
}


BoolExp::~BoolExp()
{
}

value BoolExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
