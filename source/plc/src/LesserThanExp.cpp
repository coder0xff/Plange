#include "LesserThanExp.hpp"
#include "value.hpp"



LesserThanExp::LesserThanExp()
{
}


LesserThanExp::~LesserThanExp()
{
}

std::u32string LesserThanExp::get_name() const
{
	return U"<";
}

value LesserThanExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
