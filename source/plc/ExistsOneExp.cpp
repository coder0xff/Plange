#include "ExistsOneExp.h"



ExistsOneExp::ExistsOneExp()
{
}


ExistsOneExp::~ExistsOneExp()
{
}

std::u32string ExistsOneExp::get_name() const
{
	return U"∃!";
}

bool ExistsOneExp::get_postfix() const
{
	return false;
}
