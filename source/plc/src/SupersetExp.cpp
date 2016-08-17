#include "SupersetExp.hpp"
#include "value.hpp"



SupersetExp::SupersetExp()
{
}


SupersetExp::~SupersetExp()
{
}

std::u32string SupersetExp::get_name() const
{
	return U"⊇";
}

value SupersetExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
