#include "NotLesserThanExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



NotLesserThanExp::NotLesserThanExp()
{
}


NotLesserThanExp::~NotLesserThanExp()
{
}

std::u32string NotLesserThanExp::get_name() const
{
	return U"≥";
}

value NotLesserThanExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
