#include "function_type.hpp"

#include <map>
#include <optional>

#pragma warning(push, 0)
#include "llvm/IR/DerivedTypes.h"
#pragma warning(pop)

#include "analytic_value.hpp"
#include "val.hpp"


namespace plc {
	static llvm::FunctionType make_function_type(std::vector<argument> const & types) {
		std::vector<llvm::Type *> extracted;
		for (auto t : types) {
			if (std::holds_alternative<>())
		}
			llvm::FunctionType::get()
	}

	static llvm::FunctionType * make_function_type(type const & lhs, function_type const & rhs) {
		std::vector<arg_or_pack> arguments;
		arguments.push_back(argument{ std::nullopt, val<analytic_value>(rhs) });
		arguments.insert(arguments.end(), rhs.arguments.begin(), rhs.arguments.end());
		return arguments;
	}


	function_type::function_type(bool isVolatile, bool isConst, type const & lhs, function_type const & rhs) : type(isVolatile, isConst, ) {
	}

	function_type::function_type(bool isVolatile, bool isConst, type const & lhs, type const & rhs) : isVolatile(isVolatile), isConst(isConst), arguments{ argument{ std::nullopt, lhs }, argument{ std::nullopt, rhs} } {

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

}
