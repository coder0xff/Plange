#include "PreIncExp.h"



PreIncExp::PreIncExp()
{
}


PreIncExp::~PreIncExp()
{
}

std::u32string PreIncExp::get_name() const
{
	return U"++";
}

bool PreIncExp::get_postfix() const
{
	return false;
}
