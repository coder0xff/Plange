#include "CompositionExp.hpp"
#include "value.hpp"



CompositionExp::CompositionExp()
{
}


CompositionExp::~CompositionExp()
{
}

std::u32string CompositionExp::get_name() const
{
	return U"∘";
}

value CompositionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
