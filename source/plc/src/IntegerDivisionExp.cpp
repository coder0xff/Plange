#include "IntegerDivisionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



IntegerDivisionExp::IntegerDivisionExp()
{
}


IntegerDivisionExp::~IntegerDivisionExp()
{
}

std::u32string IntegerDivisionExp::get_name() const
{
	return U"\\";
}

value IntegerDivisionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
