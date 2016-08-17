#include "ProperSubsetExp.hpp"
#include "value.hpp"



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

value ProperSubsetExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
