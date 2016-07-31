#include "AllocationExp.hpp"
#include "value.hpp"
#include "Errors.hpp"


AllocationExp::AllocationExp() {}


AllocationExp::AllocationExp(AllocationExp const & other) : argument(clone(*other.argument))
{

}

AllocationExp::~AllocationExp() {}

value AllocationExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
