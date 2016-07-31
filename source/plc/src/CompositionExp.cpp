#include "CompositionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value CompositionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
