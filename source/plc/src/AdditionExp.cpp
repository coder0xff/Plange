#include "AdditionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"


AdditionExp::AdditionExp() {}


AdditionExp::~AdditionExp() {}

std::u32string AdditionExp::get_name() const
{
	return U"+";
}

value AdditionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
