#include "BitAndExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value BitAndExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
