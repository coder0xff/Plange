#ifndef CONCRETE_VALUE_HPP
#define CONCRETE_VALUE_HPP

#include "abstract_value.hpp"

#include <llvm/IR/Value.h>
#include <memory>

namespace plc {

class concrete_value : public abstract_value {
public:
	explicit concrete_value(llvm::Value * llvm_value);

	std::unique_ptr<llvm::Value> const llvm_value;
	std::map<std::string, std::unique_ptr<abstract_value>> get_constrained_symbols() const final;
	std::shared_ptr<concrete_value> try_concretion() final;
};

}

#endif //CONCRETE_VALUE_HPP