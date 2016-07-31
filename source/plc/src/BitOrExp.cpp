#include "BitOrExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



BitOrExp::BitOrExp()
{
}


BitOrExp::~BitOrExp()
{
}

std::u32string BitOrExp::get_name() const
{
	return U"||";
}

value BitOrExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
