#include "AllocationExp.hpp"
#include "value.hpp"


AllocationExp::AllocationExp() {}


AllocationExp::AllocationExp(AllocationExp const & other) : argument(clone(*other.argument))
{

}

AllocationExp::~AllocationExp() {}

value AllocationExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
