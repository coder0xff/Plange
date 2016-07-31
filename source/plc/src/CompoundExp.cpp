#include "CompoundExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value CompoundExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
