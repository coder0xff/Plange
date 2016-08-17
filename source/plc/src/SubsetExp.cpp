#include "SubsetExp.hpp"
#include "value.hpp"



SubsetExp::SubsetExp()
{
}


SubsetExp::~SubsetExp()
{
}

std::u32string SubsetExp::get_name() const
{
	return U"⊆";
}

value SubsetExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
