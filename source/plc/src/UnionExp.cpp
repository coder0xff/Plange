#include "UnionExp.hpp"
#include "value.hpp"



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

value UnionExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
