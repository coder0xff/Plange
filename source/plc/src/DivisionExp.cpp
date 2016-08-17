#include "DivisionExp.hpp"
#include "value.hpp"



DivisionExp::DivisionExp()
{
}


DivisionExp::~DivisionExp()
{
}

std::u32string DivisionExp::get_name() const
{
	return U"/";
}

value DivisionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
