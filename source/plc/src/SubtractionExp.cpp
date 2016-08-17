#include "SubtractionExp.hpp"
#include "value.hpp"



SubtractionExp::SubtractionExp()
{
}


SubtractionExp::~SubtractionExp()
{
}

std::u32string SubtractionExp::get_name() const
{
	return U"-";
}

value SubtractionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
