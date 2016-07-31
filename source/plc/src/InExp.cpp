#include "InExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value InExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
