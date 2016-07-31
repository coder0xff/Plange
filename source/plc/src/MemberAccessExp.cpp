#include "MemberAccessExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



MemberAccessExp::MemberAccessExp()
{
}


MemberAccessExp::~MemberAccessExp()
{
}

value MemberAccessExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
