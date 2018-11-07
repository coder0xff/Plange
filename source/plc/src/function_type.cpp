#include "function_type.hpp"

#include <map>
#include <optional>

#pragma warning(push, 0)
#include "llvm/IR/DerivedTypes.h"
#pragma warning(pop)

#include "analytic_value.hpp"
#include "val.hpp"


namespace plc {
	static std::vector<argument> make_arguments(type const & lhs, function_type const & rhs)
	{
		std::vector<argument> results;
		results.push_back({ std::nullopt, lhs });
		auto rhs_args = rhs.get_arguments();
		results.insert(results.end(), rhs_args.begin(), rhs_args.end());
		return results;
	}

	static llvm::FunctionType * make_function_type(type const & lhs, function_type const & rhs) {
		std::vector<llvm::Type *> types;
		for (argument const & arg : make_arguments(lhs, rhs))
		{
			types.push_back(arg.type->get_llvm_type());
		}
		return llvm::FunctionType::get(rhs.get_return_type().get_llvm_type(), types, false);
	}

	static llvm::FunctionType * make_function_type(type const & lhs, type const & rhs) {
		return llvm::FunctionType::get(rhs.get_llvm_type(), { lhs.get_llvm_type() }, false);
	}


	function_type::function_type(bool isVolatile, bool isConst, type const & lhs, function_type const & rhs) : type(isVolatile, isConst, make_function_type(lhs, rhs)), return_type_(rhs.get_return_type()), arguments_(make_arguments(lhs, rhs)) {
	}

	function_type::function_type(bool isVolatile, bool isConst, type const & lhs, type const & rhs) : type(isVolatile, isConst, make_function_type(lhs, rhs)), return_type_(rhs), arguments_({ argument{ std::nullopt, lhs } }) {

	}


	std::map<std::string, val<analytic_value>> function_type::get_constrained_symbols() const {
		ERROR(NotImplemented, "");
	}

	natural_value* function_type::collapse() {
		ERROR(NotImplemented, "");
	}

	std::optional<val<analytic_value>> function_type::get_type() const {
		ERROR(NotImplemented, "");
	}

	std::vector<argument> function_type::get_arguments() const
	{
		return arguments_;
	}

	type const & function_type::get_return_type() const
	{
		return *return_type_;
	}
}
