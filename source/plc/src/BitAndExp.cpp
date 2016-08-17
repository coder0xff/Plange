#include "BitAndExp.hpp"
#include "value.hpp"



BitAndExp::BitAndExp()
{
}


BitAndExp::~BitAndExp()
{
}

std::u32string BitAndExp::get_name() const
{
	return U"&&";
}

value BitAndExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
