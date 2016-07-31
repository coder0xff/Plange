#include "MapsToExp.hpp"
#include "value.hpp"
#include "Errors.hpp"



MapsToExp::MapsToExp()
{
}


MapsToExp::~MapsToExp()
{
}

std::u32string MapsToExp::get_name() const
{
	return U"→";
}

value MapsToExp::evaluate() const {
	ERROR(NotImplemented, __FUNCTION__);
}
