#ifndef INCLUDED_PLC_SCOPE_HPP
#define INCLUDED_PLC_SCOPE_HPP

#include <vector>

#pragma warning(push, 0)
#include "llvm/IR/IRBuilder.h"
#pragma warning(pop)

#include "natural_value.hpp"
#include "source_code.hpp"
#include "STATEMENT.hpp"
#include "symbol.hpp"

namespace plc {

	class module;

	typedef std::unordered_map<std::u32string, val<symbol>> symbol_table;

	class scope : public analytic_value {
	public:

		scope(module & m, nptr<source_code const> source, nptr<scope> parent);

		module & m;
		nptr<source_code const> source; //will be null if Plange scope, at least while were in c++
		nptr<scope> parent;
		std::vector<val<scope>> children;

		symbol_table symbols;

		std::pair<symbol_table::iterator, bool> add_symbol(symbol const & s);
		bool is_descendent_of(scope const & s);
		bool can_execute(scope const & s);

		val<analytic_value> evaluate(EXPRESSION const & expression);
		val<analytic_value> construct(val<analytic_value> const & type, std::vector<val<analytic_value>> const & arguments);

		std::map<std::string, val<analytic_value>> get_constrained_symbols() const override;

		natural_value* collapse() override;

		static void load_dom(ptr<scope> s, STATEMENT_SCOPE const & dom);

	};
}

#endif // INCLUDED_PLC_SCOPE_HPP
