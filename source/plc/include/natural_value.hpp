#ifndef NATURAL_VALUE_HPP
#define NATURAL_VALUE_HPP

#pragma warning(push, 0)
#include <llvm/IR/Value.h>
#pragma warning(pop)

#include "analytic_value.hpp"

#include <memory>

namespace plc {

class concrete_value : public analytic_value {
	struct value_deleter
	{
		void operator()(llvm::Value * ptr) const;
	};

public:
	explicit concrete_value(llvm::Value * llvm_value);

	std::unique_ptr<llvm::Value, value_deleter> const llvm_value;
	std::map<std::string, std::unique_ptr<analytic_value>> get_constrained_symbols() const final;
	std::shared_ptr<concrete_value> try_concretion() final;
};

}

#endif //NATURAL_VALUE_HPP