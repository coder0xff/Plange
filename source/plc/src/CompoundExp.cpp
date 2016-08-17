#include "CompoundExp.hpp"
#include "value.hpp"



CompoundExp::CompoundExp()
{
}


CompoundExp::~CompoundExp()
{
}

std::u32string CompoundExp::get_name() const
{
	return U"|";
}

value CompoundExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
