#include "NorExp.hpp"
#include "value.hpp"



NorExp::NorExp()
{
}


NorExp::~NorExp()
{
}

std::u32string NorExp::get_name() const
{
	return U"↓";
}

value NorExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
