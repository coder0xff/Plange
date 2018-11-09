#ifndef INCLUDED_PLC_ANALYTIC_VALUE_HPP
#define INCLUDED_PLC_ANALYTIC_VALUE_HPP

#include <map>
#include <memory>

#include "errors.hpp"

#include "grammar.hpp"

namespace plc {

	class scope;

	class natural_value;

	class analytic_value : virtual public enable_ptr_from_this<analytic_value> {
	public:
		virtual ~analytic_value() {}
		virtual std::map<std::string, val<analytic_value>> get_constrained_symbols() const = 0;
		virtual natural_value* collapse() = 0;
		virtual std::optional<val<analytic_value>> get_type() const;

		// The value will be computed (at compile time) when dependent symbols are determined (by dependent value analysis)
		static std::optional<val<analytic_value>> make_deferred(EXPRESSION const & v);
	};

	inline std::optional<val<analytic_value>> analytic_value::get_type() const {
		ERROR(Unknown, "This object does not implement type information, and may be unsupported bootstrap functionality.");
	}

}

#endif // INCLUDED_PLC_ANALYTIC_VALUE_HPP
