#include "BijectionExp.hpp"
#include "value.hpp"



BijectionExp::BijectionExp()
{
}


BijectionExp::~BijectionExp()
{
}

std::u32string BijectionExp::get_name() const
{
	return U"↔";
}

value BijectionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
