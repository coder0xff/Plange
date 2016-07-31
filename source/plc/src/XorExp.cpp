#include "XorExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



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

value XorExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
