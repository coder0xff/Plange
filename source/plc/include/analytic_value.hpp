#ifndef ANALYTIC_VALUE_HPP
#define ANALYTIC_VALUE_HPP

#include <map>
#include <memory>

namespace plc {

	class scope;

	class natural_value;

	class analytic_value : virtual public std::enable_shared_from_this<analytic_value> {
	public:
		virtual ~analytic_value() {}
		virtual std::map<std::string, std::unique_ptr<analytic_value>> get_constrained_symbols() const = 0;
		virtual natural_value * collapse() = 0;
	};

}

#endif //ANALYTIC_VALUE_HPP