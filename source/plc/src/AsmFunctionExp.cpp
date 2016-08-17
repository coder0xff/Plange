#include "AsmFunctionExp.hpp"
#include "value.hpp"


AsmFunctionExp::AsmFunctionExp() {}


AsmFunctionExp::~AsmFunctionExp() {}

value AsmFunctionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
