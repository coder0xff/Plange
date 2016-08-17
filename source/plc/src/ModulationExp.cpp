#include "ModulationExp.hpp"
#include "value.hpp"



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

value ModulationExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
