#include "PrependExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value PrependExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
