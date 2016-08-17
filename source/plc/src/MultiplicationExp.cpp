#include "MultiplicationExp.hpp"
#include "value.hpp"



MultiplicationExp::MultiplicationExp()
{
}


MultiplicationExp::~MultiplicationExp()
{
}

std::u32string MultiplicationExp::get_name() const
{
	return U"*";
}

value MultiplicationExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
