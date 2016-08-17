#include "AdditionExp.hpp"
#include "value.hpp"


AdditionExp::AdditionExp() {}


AdditionExp::~AdditionExp() {}

std::u32string AdditionExp::get_name() const
{
	return U"+";
}

value AdditionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
