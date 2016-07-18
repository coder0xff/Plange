#include "AllocationExp.h"


AllocationExp::AllocationExp() {}


AllocationExp::AllocationExp(AllocationExp const & other) : argument(clone(*other.argument))
{

}

AllocationExp::~AllocationExp() {}
