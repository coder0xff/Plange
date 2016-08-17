#include "OrExp.hpp"
#include "value.hpp"



OrExp::OrExp()
{
}


OrExp::~OrExp()
{
}

std::u32string OrExp::get_name() const
{
	return U"∨";
}

value OrExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
