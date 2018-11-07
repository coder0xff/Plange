#ifndef INCLUDED_FUNCTION_TYPE_HPP
#define INCLUDED_FUNCTION_TYPE_HPP

#include "analytic_value.hpp"
#include "type.hpp"

namespace plc {
	struct argument {
		std::optional<std::string> name;
		val<type> type;
	};

	class function_type : public type {
	public:
		function_type(bool isVolatile, bool isConst, type const & lhs, function_type const & rhs);
		function_type(bool isVolatile, bool isConst, type const & lhs, type const & rhs);
		std::map<std::string, val<analytic_value>> get_constrained_symbols() const override;
		natural_value* collapse() override;
		std::optional<val<analytic_value>> get_type() const override;

	private:
		val<type> return_type_;
		std::vector<argument> types_;
	};
}

#endif
