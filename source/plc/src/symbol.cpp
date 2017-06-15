#include "symbol.hpp"

namespace plc
{
symbol::symbol(std::u32string const& name, std::shared_ptr<analytic_value> const& value, bool isVariable, bool isLocal, bool isExtern) : name(name), value(value), isVariable(isVariable), isLocal(isLocal), isExtern(isExtern)
{
}

symbol symbol::delocalize() const
{
	return symbol(name, value, isVariable, false);
}
}
