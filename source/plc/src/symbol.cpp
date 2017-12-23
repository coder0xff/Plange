#include "symbol.hpp"

namespace plc
{
symbol::symbol(std::u32string const& name, std::shared_ptr<analytic_value> const& value, bool const isVariable, bool const isLocal, bool const isExtern) : name(name), value(value), is_variable(isVariable), is_local(isLocal), is_extern(isExtern)
{
}

symbol symbol::delocalize() const
{
	return symbol(name, value, is_variable, false);
}
}
