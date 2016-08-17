#include "InExp.hpp"
#include "value.hpp"



InExp::InExp()
{
}


InExp::~InExp()
{
}

std::u32string InExp::get_name() const
{
	return U"∈";
}

value InExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
