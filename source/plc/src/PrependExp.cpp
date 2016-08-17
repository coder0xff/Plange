#include "PrependExp.hpp"
#include "value.hpp"



PrependExp::PrependExp()
{
}


PrependExp::~PrependExp()
{
}

std::u32string PrependExp::get_name() const
{
	return U"&";
}

value PrependExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
