#include "ProperSubsetExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ProperSubsetExp::ProperSubsetExp()
{
}


ProperSubsetExp::~ProperSubsetExp()
{
}

std::u32string ProperSubsetExp::get_name() const
{
	return U"⊂";
}

value ProperSubsetExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
