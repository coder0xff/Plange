#include "IffExp.hpp"
#include "value.hpp"



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

value IffExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
