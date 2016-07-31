#include "AllocationExp.hpp"


AllocationExp::AllocationExp() {}


AllocationExp::AllocationExp(AllocationExp const & other) : argument(clone(*other.argument))
{

}

AllocationExp::~AllocationExp() {}
