#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <vector>
#include "source_code.hpp"
#pragma warning(push, 0)
#include "symengine/symbol.h"
#pragma warning(pop)

class scope {
public:
	explicit scope(source_code& source);
	~scope();
	scope* parent;
	std::vector<scope> children;
	source_code const& source_code;
	std::vector<SymEngine::Symbol> symbols;
	bool is_pure;
	bool is_atomic;
	bool is_reentrant;
	//FunctionModel model;
	//std::vector<SideEffect> sideEffects;
	bool is_descendent_of(scope const& s);
	bool can_execute(scope const& s);
};

#endif //SCOPE_HPP
