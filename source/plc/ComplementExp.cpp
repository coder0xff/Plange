#include "ComplementExp.h"



ComplementExp::ComplementExp()
{
}


ComplementExp::~ComplementExp()
{
}

std::u32string ComplementExp::get_name() const
{
	return U"ᶜ";
}

bool ComplementExp::get_postfix() const
{
	return true;
}
