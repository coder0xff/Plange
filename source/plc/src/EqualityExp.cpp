#include "EqualityExp.hpp"
#include "value.hpp"



EqualityExp::EqualityExp()
{
}


EqualityExp::~EqualityExp()
{
}

std::u32string EqualityExp::get_name() const
{
	return U"=";
}

value EqualityExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
