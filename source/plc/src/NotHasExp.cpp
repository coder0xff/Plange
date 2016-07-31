#include "NotHasExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



NotHasExp::NotHasExp()
{
}


NotHasExp::~NotHasExp()
{
}

std::u32string NotHasExp::get_name() const
{
	return U"∌";
}

value NotHasExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
