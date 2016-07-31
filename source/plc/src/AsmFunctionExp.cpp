#include "AsmFunctionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"


AsmFunctionExp::AsmFunctionExp() {}


AsmFunctionExp::~AsmFunctionExp() {}

value AsmFunctionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
