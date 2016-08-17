#include "ShiftLExp.hpp"
#include "value.hpp"

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

value ShiftLExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
