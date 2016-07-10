#include "value.h"
#include "Errors.h"

value::value(value* type, const std::vector<int8_t>& storage) : type(type), storage(storage) { }

bool value::operator==(value const & rhs)
{
	emit_NotImplemented(__FUNCTION__);
	throw;
}
