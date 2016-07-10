#include "PreDecExp.h"



PreDecExp::PreDecExp()
{
}


PreDecExp::~PreDecExp()
{
}

std::u32string PreDecExp::get_name() const
{
	return U"--";
}

bool PreDecExp::get_postfix() const
{
	return false;
}
