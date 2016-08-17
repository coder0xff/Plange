#include "InequalityExp.hpp"
#include "value.hpp"



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

value InequalityExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
