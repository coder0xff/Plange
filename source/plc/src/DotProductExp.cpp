#include "DotProductExp.hpp"
#include "value.hpp"



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

value DotProductExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
