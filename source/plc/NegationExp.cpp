#include "NegationExp.h"



NegationExp::NegationExp()
{
}


NegationExp::~NegationExp()
{
}

std::u32string NegationExp::get_name() const
{
	return U"-";
}

bool NegationExp::get_postfix() const
{
	return false;
}
