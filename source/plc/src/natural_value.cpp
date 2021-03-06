#include "natural_value.hpp"

#include <memory>

#include "errors.hpp"

namespace plc {

std::map<std::string, val<analytic_value>> natural_value::get_constrained_symbols() const
{
	ERROR(NotImplemented, "");
}


natural_value * natural_value::collapse()
{
	return this;
}


std::optional<val<analytic_value>> natural_value::get_type() const
{
	return type;
}

void natural_value::value_deleter::operator()(llvm::Value* ptr) const
{
	ptr->deleteValue();
}

natural_value::natural_value(llvm::Value* llvmValue) : llvm_value(llvmValue, value_deleter()) {}

}
