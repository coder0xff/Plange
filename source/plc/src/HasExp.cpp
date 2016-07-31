#include "HasExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



HasExp::HasExp()
{
}


HasExp::~HasExp()
{
}

std::u32string HasExp::get_name() const
{
	return U"∋";
}

value HasExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
