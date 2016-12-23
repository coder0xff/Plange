#ifndef CONCRETE_VALUE_HPP
#define CONCRETE_VALUE_HPP

#include "abstract_value.hpp"

#include <llvm/IR/Value.h>
#include <memory>

namespace plc {

class concrete_value : public abstract_value {
public:
	std::unique_ptr<llvm::Value> const underlying;
	std::map<std::string, std::unique_ptr<abstract_value>> get_constrained_symbols() const final;
	std::shared_ptr<concrete_value> try_concretion() final;
	explicit concrete_value(llvm::Value * value);
};

}

#endif //CONCRETE_VALUE_HPP