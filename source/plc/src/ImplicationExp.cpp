#include "ImplicationExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ImplicationExp::ImplicationExp()
{
}


ImplicationExp::~ImplicationExp()
{
}

std::u32string ImplicationExp::get_name() const
{
	return U"⇒";
}

value ImplicationExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
