#include "EqualityExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value EqualityExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
