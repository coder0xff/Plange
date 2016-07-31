#include "UnionExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



UnionExp::UnionExp()
{
}


UnionExp::~UnionExp()
{
}

std::u32string UnionExp::get_name() const
{
	return U"∪";
}

value UnionExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
