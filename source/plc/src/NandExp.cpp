#include "NandExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



NandExp::NandExp()
{
}


NandExp::~NandExp()
{
}

std::u32string NandExp::get_name() const
{
	return U"↑";
}

value NandExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
