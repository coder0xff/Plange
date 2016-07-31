#include "IntersectionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



IntersectionExp::IntersectionExp()
{
}


IntersectionExp::~IntersectionExp()
{
}

std::u32string IntersectionExp::get_name() const
{
	return U"∩";
}

value IntersectionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
