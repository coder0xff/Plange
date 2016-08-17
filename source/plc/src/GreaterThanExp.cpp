#include "GreaterThanExp.hpp"
#include "value.hpp"



GreaterThanExp::GreaterThanExp()
{
}


GreaterThanExp::~GreaterThanExp()
{
}

std::u32string GreaterThanExp::get_name() const
{
	return U">";
}

value GreaterThanExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
