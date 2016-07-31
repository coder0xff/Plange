#include "InequalityExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



InequalityExp::InequalityExp()
{
}


InequalityExp::~InequalityExp()
{
}

std::u32string InequalityExp::get_name() const
{
	return U"≠";
}

value InequalityExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
