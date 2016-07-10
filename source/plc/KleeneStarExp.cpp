#include "KleeneStarExp.h"



KleeneStarExp::KleeneStarExp()
{
}


KleeneStarExp::~KleeneStarExp()
{
}

std::u32string KleeneStarExp::get_name() const
{
	return U"*";
}

bool KleeneStarExp::get_postfix() const
{
	return true;
}
