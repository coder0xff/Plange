#include "MapExp.hpp"
#include "value.hpp"



MapExp::MapExp()
{
}


MapExp::MapExp(MapExp const & other)
{
	for (auto const & entry : other.elements) {
		elements.emplace(std::piecewise_construct, make_tuple(move(clone(*entry.first))), make_tuple(move(clone(*entry.second))));
	}
}

MapExp::~MapExp()
{
}

value MapExp::evaluate(execution_context &exc) const {
	ERROR(NotImplemented, __FUNCTION__);
}
