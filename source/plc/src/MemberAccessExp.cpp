#include "MemberAccessExp.hpp"
#include "value.hpp"



MemberAccessExp::MemberAccessExp()
{
}


MemberAccessExp::~MemberAccessExp()
{
}

value MemberAccessExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
