#ifndef ABSTRACT_VALUE_HPP
#define ABSTRACT_VALUE_HPP

#include <map>
#include <memory>

namespace plc {

	class scope;

	class concrete_value;

	class abstract_value : virtual public std::enable_shared_from_this<abstract_value> {
	public:
		virtual ~abstract_value() {}
		virtual std::map<std::string, std::unique_ptr<abstract_value>> get_constrained_symbols() const = 0;
		virtual std::shared_ptr<concrete_value> try_concretion() = 0;
	};

}

#endif //ABSTRACT_VALUE_HPP