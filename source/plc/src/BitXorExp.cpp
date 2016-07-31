#include "BitXorExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



BitXorExp::BitXorExp()
{
}


BitXorExp::~BitXorExp()
{
}

std::u32string BitXorExp::get_name() const
{
	return U"^^";
}

value BitXorExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
