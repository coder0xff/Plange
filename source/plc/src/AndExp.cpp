#include "AndExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value AndExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
