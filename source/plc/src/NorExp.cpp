#include "NorExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value NorExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
