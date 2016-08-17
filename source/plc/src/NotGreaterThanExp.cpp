#include "NotGreaterThanExp.hpp"
#include "value.hpp"



NotGreaterThanExp::NotGreaterThanExp()
{
}


NotGreaterThanExp::~NotGreaterThanExp()
{
}

std::u32string NotGreaterThanExp::get_name() const
{
	return U"≤";
}

value NotGreaterThanExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
