#ifndef INCLUDED_PLC_NATURAL_VALUE_HPP
#define INCLUDED_PLC_NATURAL_VALUE_HPP

#include <memory>

#pragma warning(push, 0)
#include "llvm/IR/Value.h"
#pragma warning(pop)

#include "analytic_value.hpp"

namespace plc {

class natural_value : public analytic_value {
	struct value_deleter
	{
		void operator()(llvm::Value * ptr) const;
	};

public:
	explicit natural_value(llvm::Value * llvmValue);

	std::unique_ptr<llvm::Value, value_deleter> const llvm_value;
	std::map<std::string, val<analytic_value>> get_constrained_symbols() const final;
	std::optional<val<analytic_value>> type;

	natural_value * collapse() override;
	std::optional<val<analytic_value>> get_type() const final;

};

}

#endif // INCLUDED_PLC_NATURAL_VALUE_HPP