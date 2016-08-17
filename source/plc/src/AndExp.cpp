#include "AndExp.hpp"
#include "value.hpp"



AndExp::AndExp()
{
}


AndExp::~AndExp()
{
}

std::u32string AndExp::get_name() const
{
	return U"∧";
}

value AndExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
