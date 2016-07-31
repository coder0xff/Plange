#include "IffExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



IffExp::IffExp()
{
}


IffExp::~IffExp()
{
}

std::u32string IffExp::get_name() const
{
	return U"⇔";
}

value IffExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
