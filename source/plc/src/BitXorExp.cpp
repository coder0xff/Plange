#include "BitXorExp.hpp"
#include "value.hpp"



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

value BitXorExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
