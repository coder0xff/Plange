#include "SubtractionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value SubtractionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
