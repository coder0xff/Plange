#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <vector>
#include "source_code.hpp"
#pragma warning(push, 0)
#include <symengine/symbol.h>
#include <llvm/IR/Value.h>
#pragma warning(pop)

class scope {
public:
	explicit scope(source_code& source, scope* const parent, parlex::match const & syntax);
	~scope();
	scope* const parent;
	std::vector<scope> children;
	source_code const& source_code_;
	std::vector<SymEngine::Symbol> symbols;
	std::map<std::u32string, llvm::Value *> string_literals;
	bool is_pure;
	bool is_atomic;
	bool is_reentrant;
	//FunctionModel model;
	//std::vector<SideEffect> sideEffects;
	bool is_descendent_of(scope const& s);
	bool can_execute(scope const& s);
};

#endif //SCOPE_HPP
