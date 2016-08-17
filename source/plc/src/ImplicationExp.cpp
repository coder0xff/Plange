#include "ImplicationExp.hpp"
#include "value.hpp"



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

value ImplicationExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
