#include "BitOrExp.hpp"
#include "value.hpp"



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

value BitOrExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
