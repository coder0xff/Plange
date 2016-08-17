#include "NotInExp.hpp"
#include "value.hpp"



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

value NotInExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
