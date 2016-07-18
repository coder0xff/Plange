#include "IfExp.h"



IfExp::IfExp()
{
}


IfExp::IfExp(IfExp const & other) : else_(clone(*other.else_))
{
	for (auto const & pair : other.pairs) {
		pairs.resize(pairs.size() + 1);
		auto & p = *pairs.rbegin();
		auto condition = clone(*pair.first);
		p.first.swap(condition);
		auto val = clone(*pair.second);
		p.second.swap(val);
	}
}

IfExp::~IfExp()
{
}
