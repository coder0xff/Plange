#include "MultiplicationExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value MultiplicationExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
