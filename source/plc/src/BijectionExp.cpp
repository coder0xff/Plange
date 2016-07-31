#include "BijectionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value BijectionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
