#include "XorExp.hpp"
#include "value.hpp"



XorExp::XorExp()
{
}


XorExp::~XorExp()
{
}

std::u32string XorExp::get_name() const
{
	return U"⊕";
}

value XorExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
