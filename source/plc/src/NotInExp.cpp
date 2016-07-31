#include "NotInExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



NotInExp::NotInExp()
{
}


NotInExp::~NotInExp()
{
}

std::u32string NotInExp::get_name() const
{
	return U"∉";
}

value NotInExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
