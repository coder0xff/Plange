#include "MapsToExp.hpp"
#include "value.hpp"



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

value MapsToExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
