#include "ProperSupersetExp.hpp"
#include "value.hpp"



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

value ProperSupersetExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
