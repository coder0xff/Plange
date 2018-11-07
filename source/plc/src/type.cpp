#include "type.hpp"

#include <optional>

#include "analytic_value.hpp"
#include "val.hpp"

plc::type::type(bool is_volatile, bool is_const, llvm::Type * underlying) : is_volatile_(is_volatile), is_const_(is_const), underlying_(underlying) {
	
}

std::map<std::string, val<plc::analytic_value>> plc::type::get_constrained_symbols() const
{
	ERROR(NotImplemented, "");
}

plc::natural_value* plc::type::collapse()
{
	ERROR(NotImplemented, "");
}

std::optional<val<plc::analytic_value>> plc::type::get_type() const
{
	ERROR(NotImplemented, "");
}

llvm::Type * plc::type::get_llvm_type() const { return underlying_; }
