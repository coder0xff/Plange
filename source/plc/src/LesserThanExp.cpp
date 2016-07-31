#include "LesserThanExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value LesserThanExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
