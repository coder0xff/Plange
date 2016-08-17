#include "AddSubExp.hpp"
#include "value.hpp"



AddSubExp::AddSubExp()
{
}


AddSubExp::~AddSubExp()
{
}

std::u32string AddSubExp::get_name() const
{
	return U"±";
}

value AddSubExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
