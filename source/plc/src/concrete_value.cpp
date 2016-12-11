#include "concrete_value.hpp"

#include <memory>

#include "errors.hpp"

namespace plc {

std::map<std::string, std::unique_ptr<abstract_value>> concrete_value::get_constrained_symbols() const
{
	ERROR(NotImplemented, "");
}

std::shared_ptr<concrete_value> concrete_value::try_concretion()
{
	return std::dynamic_pointer_cast<concrete_value>(shared_from_this());
}

concrete_value::concrete_value(llvm::Value* value) : underlying(value) {}
}
