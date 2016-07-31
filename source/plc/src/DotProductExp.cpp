#include "DotProductExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



DotProductExp::DotProductExp()
{
}


DotProductExp::~DotProductExp()
{
}

std::u32string DotProductExp::get_name() const
{
	return U"⋅";
}

value DotProductExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
