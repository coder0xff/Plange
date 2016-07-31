#include "NotGreaterThanExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value NotGreaterThanExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
