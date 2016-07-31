#include "StringExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



StringExp::StringExp(std::string const & value) : val(value)
{
}


StringExp::~StringExp()
{
}

value StringExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
