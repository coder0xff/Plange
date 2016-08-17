#include "NonNegativeNumberExp.hpp"
#include "value.hpp"


NonNegativeNumberExp::NonNegativeNumberExp(std::u32string const & asString) : as_string(asString) {}


NonNegativeNumberExp::~NonNegativeNumberExp() {}

value NonNegativeNumberExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
