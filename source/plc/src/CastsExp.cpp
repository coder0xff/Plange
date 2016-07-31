#include "CastsExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value CastsExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
