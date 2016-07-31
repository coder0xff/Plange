#include "ConditionalExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ConditionalExp::ConditionalExp()
{
}


ConditionalExp::ConditionalExp(ConditionalExp const & other) : condition(clone(*other.condition)), true_case(clone(*other.true_case)), false_case(clone(*other.false_case))
{

}

ConditionalExp::~ConditionalExp()
{
}

value ConditionalExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
