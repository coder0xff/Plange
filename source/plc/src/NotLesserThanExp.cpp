#include "NotLesserThanExp.hpp"
#include "value.hpp"



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

value NotLesserThanExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
