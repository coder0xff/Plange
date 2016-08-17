#include "IntegerDivisionExp.hpp"
#include "value.hpp"



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

value IntegerDivisionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
