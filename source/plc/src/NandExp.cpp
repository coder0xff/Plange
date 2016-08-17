#include "NandExp.hpp"
#include "value.hpp"



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

value NandExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
