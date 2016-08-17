#include "CastsExp.hpp"
#include "value.hpp"



CastsExp::CastsExp()
{
}


CastsExp::~CastsExp()
{
}

std::u32string CastsExp::get_name() const
{
	return U"casts";
}

value CastsExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
