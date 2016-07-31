#include "SubsetExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value SubsetExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
