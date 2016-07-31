#include "IsExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



IsExp::IsExp()
{
}


IsExp::~IsExp()
{
}

std::u32string IsExp::get_name() const
{
	return U"is";
}

value IsExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
