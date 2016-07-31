#include "CrossProductExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



CrossProductExp::CrossProductExp()
{
}


CrossProductExp::~CrossProductExp()
{
}

std::u32string CrossProductExp::get_name() const
{
	return U"×";
}

value CrossProductExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
