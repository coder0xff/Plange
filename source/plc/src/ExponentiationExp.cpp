#include "ExponentiationExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ExponentiationExp::ExponentiationExp()
{
}


ExponentiationExp::~ExponentiationExp()
{
}

std::u32string ExponentiationExp::get_name() const
{
	return U"^";
}

value ExponentiationExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
