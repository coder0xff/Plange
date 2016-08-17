#include "StringExp.hpp"
#include "value.hpp"



StringExp::StringExp(std::string const & value) : val(value)
{
}


StringExp::~StringExp()
{
}

value StringExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
