#ifndef INCLUDED_PLC_SYMBOL_HPP
#define INCLUDED_PLC_SYMBOL_HPP

#include <map>
#include <memory>
#include <string>

namespace plc {

class analytic_value;

class symbol {
public:
	std::u32string const name;
	std::shared_ptr<analytic_value> const value;
	bool const is_variable;
	bool const is_local;
	bool const is_extern;
	//is unbound if isVariable && value.get() == nullptr

	symbol(std::u32string const & name, std::shared_ptr<analytic_value> const & value, bool isVariable, bool isLocal = true, bool isExtern = false);
	symbol & operator=(symbol const & other) = delete;
	symbol delocalize() const;
};

}

#endif // INCLUDED_PLC_SYMBOL_HPP
