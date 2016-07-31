#include "TupleExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



TupleExp::TupleExp()
{
}


TupleExp::~TupleExp()
{
}

value TupleExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
