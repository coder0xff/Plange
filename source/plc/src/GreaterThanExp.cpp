#include "GreaterThanExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



GreaterThanExp::GreaterThanExp()
{
}


GreaterThanExp::~GreaterThanExp()
{
}

std::u32string GreaterThanExp::get_name() const
{
	return U">";
}

value GreaterThanExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
