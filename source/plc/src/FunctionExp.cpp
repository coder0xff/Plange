#include "FunctionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



FunctionExp::FunctionExp()
{
}


FunctionExp::~FunctionExp()
{
}

value FunctionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
