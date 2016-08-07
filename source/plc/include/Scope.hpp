#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <vector>
#include "SourceCode.hpp"
#include "Constant.hpp"
#include "Assertion.hpp"
#include "Statement.hpp"
#include "Variable.hpp"
#include "FunctionModel.hpp"
#include "SideEffect.hpp"

class Scope {
public:
	explicit Scope(SourceCode& source);
	~Scope();
	Scope* parent;
	std::vector<Scope> children;
	SourceCode const& sourceCode;
	std::vector<Constant> constants;
	std::vector<Assertion> assertions;
	std::vector<Statement> statements;
	std::vector<Variable> variables;
	bool isPure;
	bool isAtomic;
	bool isReentrant;
	FunctionModel model;
	std::vector<SideEffect> sideEffects;
	bool isDescendentOf(Scope const& s);
	bool canExecute(Scope const& s);
};

#endif //SCOPE_HPP
