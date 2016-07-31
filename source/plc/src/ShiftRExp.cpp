#include "ShiftRExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ShiftRExp::ShiftRExp()
{
}


ShiftRExp::~ShiftRExp()
{
}

std::u32string ShiftRExp::get_name() const
{
	return U">>";
}

value ShiftRExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
