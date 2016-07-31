#include "RangeExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



RangeExp::RangeExp()
{
}


RangeExp::~RangeExp()
{
}

value RangeExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
