#include "natural_value.hpp"

#include <memory>

#include "errors.hpp"

namespace plc {

	std::map<std::string, std::unique_ptr<analytic_value>> natural_value::get_constrained_symbols() const
	{
		ERROR(NotImplemented, "");
	}


	natural_value * natural_value::collapse()
	{
		return this;
	}

	void natural_value::value_deleter::operator()(llvm::Value* ptr) const
	{
		ptr->deleteValue();
	}

	natural_value::natural_value(llvm::Value* llvm_value) : llvm_value(llvm_value, value_deleter()) {}

}
