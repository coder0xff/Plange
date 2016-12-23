#ifndef SYMBOL_HPP
#define SYMBOL_HPP
#include <string>
#include <memory>
#include <map>

namespace plc {

class abstract_value;

class symbol {
public:
	std::u32string const name;
	std::shared_ptr<abstract_value> const value;
	bool const isVariable;
	bool const isLocal;
	//is unbound if !constant && !isVariable

	symbol(std::u32string const & name, std::shared_ptr<abstract_value> const & value, bool isVariable, bool isLocal = true);
	symbol & operator=(symbol const & other) = delete;
	symbol delocalize() const;
};

typedef std::map<std::u32string, symbol> symbol_table;

}

#endif //SYMBOL_HPP
