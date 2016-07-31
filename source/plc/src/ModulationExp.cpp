#include "ModulationExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ModulationExp::ModulationExp()
{
}


ModulationExp::~ModulationExp()
{
}

std::u32string ModulationExp::get_name() const
{
	return U"%";
}

value ModulationExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
