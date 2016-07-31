#include "SymmetricDifferenceExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value SymmetricDifferenceExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
