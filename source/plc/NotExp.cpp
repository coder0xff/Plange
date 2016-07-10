#include "NotExp.h"



NotExp::NotExp()
{
}


NotExp::~NotExp()
{
}

std::u32string NotExp::get_name() const
{
	return U"¬";
}

bool NotExp::get_postfix() const
{
	return false;
}
