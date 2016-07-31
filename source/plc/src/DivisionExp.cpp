#include "DivisionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value DivisionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
