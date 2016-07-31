#include "NullCoalesceExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value NullCoalesceExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
