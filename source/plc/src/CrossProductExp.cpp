#include "CrossProductExp.hpp"
#include "value.hpp"



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

value CrossProductExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
