#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <vector>

#pragma warning(push, 0)
#include <llvm/IR/IRBuilder.h>
#pragma warning(pop)

#include "natural_value.hpp"
#include "source_code.hpp"
#include "STATEMENT.hpp"
#include "symbol.hpp"

namespace plc {
struct EXPRESSION;

class module;

typedef std::unordered_map<std::u32string, symbol> symbol_table;

class scope : public natural_value {
public:

	scope(module & m, source_code const * source, scope * parent);
	scope(module & m, source_code const * source, scope * parent, STATEMENT_SCOPE const & dom);
	~scope() = default;

	module & m;
	source_code const * const source; //will be null if Plange scope, at least while were in c++
	scope * const parent;
	std::vector<scope> children;

	symbol_table symbols;

	bool add_symbol(symbol const& s);
	bool is_descendent_of(scope const& s);
	bool can_execute(scope const& s);

	analytic_value * static_resolve(EXPRESSION const & expression);

private:
};

}
#endif //SCOPE_HPP
