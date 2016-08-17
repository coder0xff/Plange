#include "HasExp.hpp"
#include "value.hpp"



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

value HasExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
