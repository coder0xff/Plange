#include "TypeExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



TypeExp::TypeExp()
{
}


TypeExp::~TypeExp()
{
}

value TypeExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
