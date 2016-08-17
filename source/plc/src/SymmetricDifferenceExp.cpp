#include "SymmetricDifferenceExp.hpp"
#include "value.hpp"



SymmetricDifferenceExp::SymmetricDifferenceExp()
{
}


SymmetricDifferenceExp::~SymmetricDifferenceExp()
{
}

std::u32string SymmetricDifferenceExp::get_name() const
{
	return U"⊖";
}

value SymmetricDifferenceExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
