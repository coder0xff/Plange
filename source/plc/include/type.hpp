#ifndef INCLUDED_TYPE_HPP
#define INCLUDED_TYPE_HPP

#include "analytic_value.hpp"

#pragma warning(push, 0)
#include "llvm/IR/Type.h"
#pragma warning(pop)

namespace plc {
	class type : public analytic_value {
	public:
		type(bool is_volatile, bool is_const, llvm::Type * underlying);
		virtual ~type() = default;
		std::map<std::string, val<analytic_value>> get_constrained_symbols() const override;
		natural_value* collapse() override;
		std::optional<val<analytic_value>> get_type() const override;
		llvm::Type * get_llvm_type() const;

	private:
		bool is_volatile_;
		bool is_const_;
		llvm::Type * underlying_;
	};
}

#endif