#include "ExistsExp.h"



ExistsExp::ExistsExp()
{
}


ExistsExp::~ExistsExp()
{
}

std::u32string ExistsExp::get_name() const
{
	return U"∃";
}

bool ExistsExp::get_postfix() const
{
	return false;
}
