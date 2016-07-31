#include "OrExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



OrExp::OrExp()
{
}


OrExp::~OrExp()
{
}

std::u32string OrExp::get_name() const
{
	return U"∨";
}

value OrExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
