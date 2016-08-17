#include "FunctionExp.hpp"
#include "value.hpp"



FunctionExp::FunctionExp()
{
}


FunctionExp::~FunctionExp()
{
}

value FunctionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
