#include "IsExp.hpp"
#include "value.hpp"



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

value IsExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
