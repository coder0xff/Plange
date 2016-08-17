#include "IntersectionExp.hpp"
#include "value.hpp"



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

value IntersectionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
