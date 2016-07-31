#include "NonNegativeNumberExp.hpp"
#include "value.hpp"
#include "Errors.hpp"


NonNegativeNumberExp::NonNegativeNumberExp(std::u32string const & asString) : as_string(asString) {}


NonNegativeNumberExp::~NonNegativeNumberExp() {}

value NonNegativeNumberExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
