#include "SupersetExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value SupersetExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
