#include "NullCoalesceExp.hpp"
#include "value.hpp"



NullCoalesceExp::NullCoalesceExp()
{
}


NullCoalesceExp::~NullCoalesceExp()
{
}

std::u32string NullCoalesceExp::get_name() const
{
	return U"??";
}

value NullCoalesceExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
