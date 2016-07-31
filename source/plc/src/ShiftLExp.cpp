#include "ShiftLExp.hpp"
#include "value.hpp"
#include "Errors.hpp"

ShiftLExp::ShiftLExp()
{
}


ShiftLExp::~ShiftLExp()
{
}

std::u32string ShiftLExp::get_name() const
{
	return U"<<";
}

value ShiftLExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
