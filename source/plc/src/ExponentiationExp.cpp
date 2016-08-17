#include "ExponentiationExp.hpp"
#include "value.hpp"



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

value ExponentiationExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
