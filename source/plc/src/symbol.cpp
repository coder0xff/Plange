#include "symbol.hpp"

namespace plc {

symbol::symbol(std::u32string const& name, std::shared_ptr<abstract_value> const& value, bool isVariable, bool isLocal) : name(name), value(value), isVariable(isVariable), isLocal(isLocal) {}

symbol symbol::delocalize() const {
	return symbol(name, value, isVariable, false);
}

}
