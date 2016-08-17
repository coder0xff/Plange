#include "ShiftRExp.hpp"
#include "value.hpp"



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

value ShiftRExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
