#include "TypeExp.hpp"
#include "value.hpp"



TypeExp::TypeExp()
{
}


TypeExp::~TypeExp()
{
}

value TypeExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
