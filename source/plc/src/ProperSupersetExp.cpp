#include "ProperSupersetExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



ProperSupersetExp::ProperSupersetExp()
{
}


ProperSupersetExp::~ProperSupersetExp()
{
}

std::u32string ProperSupersetExp::get_name() const
{
	return U"⊃";
}

value ProperSupersetExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
