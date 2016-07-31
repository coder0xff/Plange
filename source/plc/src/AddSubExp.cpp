#include "AddSubExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



AddSubExp::AddSubExp()
{
}


AddSubExp::~AddSubExp()
{
}

std::u32string AddSubExp::get_name() const
{
	return U"±";
}

value AddSubExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
