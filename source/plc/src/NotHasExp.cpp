#include "NotHasExp.hpp"
#include "value.hpp"



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

value NotHasExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
